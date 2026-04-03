/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_sync.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:57:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:29:24 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>
#include <unistd.h>

/**
 * @brief Synchronizes the coder thread at startup and offsets odd IDs.
 *
 * @param coder Entity to be synchronized
 */
void	coder_sync(t_coder *coder)
{
	pthread_mutex_lock(coder->start_mutex);
	while (!(*coder->can_start))
		pthread_cond_wait(coder->start_cond, coder->start_mutex);
	pthread_mutex_unlock(coder->start_mutex);
	coder_reset_burnout_at_thread_safe(coder);
	if (coder->id % 2 != 0)
		usleep((coder->sim->args.time_to_compile * 1000) / 2);
}
