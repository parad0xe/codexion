/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_sync.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:57:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:55:24 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	coder_sync(t_coder *coder)
{
	pthread_mutex_lock(coder->start_mutex);
	pthread_mutex_unlock(coder->start_mutex);
	time_set_abstimeout(&coder->burnout_at, coder->time_to_burnout);
	if (coder->id % 2 != 0)
		usleep((coder->time_to_compile * 1000) / 2);
	printf("coder %d started\n", coder->id);
}
