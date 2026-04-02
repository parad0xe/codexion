/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:44:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:19:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>

/**
 * @brief Safely checks if the coder's running status is active.
 *
 * @param coder Entity whose running state is being checked
 * @return 1 if the coder is currently running, 0 otherwise
 */
int	coder_is_running_thread_safe(t_coder *coder)
{
	int	is_running;

	pthread_mutex_lock(&coder->is_running_mutex);
	is_running = coder->is_running;
	pthread_mutex_unlock(&coder->is_running_mutex);
	return (is_running);
}

/**
 * @brief Safely updates the coder's running status.
 *
 * @param coder Entity whose running state is being updated
 * @param is_running New running status flag to be applied
 */
void	coder_set_running_thread_safe(t_coder *coder, int is_running)
{
	pthread_mutex_lock(&coder->is_running_mutex);
	coder->is_running = is_running;
	pthread_mutex_unlock(&coder->is_running_mutex);
}
