/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_sync.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:57:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:40:23 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <pthread.h>
#include <unistd.h>

void	coder_sync(t_coder *coder)
{
	pthread_mutex_lock(coder->start_mutex);
	while (!(*coder->can_start))
		pthread_cond_wait(coder->start_cond, coder->start_mutex);
	pthread_mutex_unlock(coder->start_mutex);
	time_set_abstimeout(&coder->burnout_at, coder->sim->args.time_to_burnout);
	if (coder->id % 2 != 0)
		usleep((coder->sim->args.time_to_compile * 1000) / 2);
}
