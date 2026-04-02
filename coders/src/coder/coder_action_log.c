/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_log.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:24:41 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:15:38 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>

/**
 * @brief Prints a formatted message strictly maintaining chronological order.
 *
 * @param coder Entity executing the action
 * @param message Action description to be printed
 * @param require_running_coder Flag to enforce running state verification
 */
void	coder_log_thread_safe(t_coder *coder, char *message,
		int require_running_coder)
{
	pthread_mutex_lock(&coder->sim->log_mutex);
	if (!require_running_coder || coder_is_running_thread_safe(coder))
	{
		printf("%zu %d %s\n", time_get_elapsed_ms(&coder->sim->started_at),
			coder->id, message);
	}
	pthread_mutex_unlock(&coder->sim->log_mutex);
}
