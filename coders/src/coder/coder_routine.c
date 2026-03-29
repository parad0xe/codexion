/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 01:11:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	_on_start(t_coder *coder)
{
	pthread_mutex_lock(coder->start_mutex);
	pthread_mutex_unlock(coder->start_mutex);
	coder->last_compile_start = get_current_timestamp();
	set_absolute_timeout(&coder->burnout_at, coder->time_to_burnout);
	if (coder->id % 2 != 0)
		usleep((coder->time_to_compile * 1000) / 2);
	printf("coder %d started\n", coder->id);
}

// create difference between fifo and edf on powerful pc
// usleep((coder->time_to_refactor + (rand() % 70)) * 1000);
static void	_on_acquire_dongle(t_coder *coder)
{
	printf("coder %d acquire dongles\n", coder->id);
	coder->last_compile_start = get_current_timestamp();
	set_absolute_timeout(&coder->burnout_at, coder->time_to_burnout);
	usleep(coder->time_to_compile * 1000);
	coder_release_dongles(coder);
	usleep(coder->time_to_debug * 1000);
	usleep(coder->time_to_refactor * 1000);
}

void	*coder_routine(void *thread_args)
{
	t_coder	*coder;
	int		acquire_dongle;
	size_t	i;

	coder = (t_coder *)thread_args;
	_on_start(coder);
	i = 0;
	while (i < coder->number_of_compiles)
	{
		acquire_dongle = coder_wait_dongles(coder);
		if (acquire_dongle)
			_on_acquire_dongle(coder);
		else
		{
			printf("coder %d BURNOUT\n", coder->id);
			exit(1);
			break ;
		}
		i++;
	}
	return (NULL);
}
