/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:44:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:36:40 by nlallema         ###   ########lyon.fr   */
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

	pthread_mutex_lock(&coder->access_mutex);
	is_running = coder->is_running;
	pthread_mutex_unlock(&coder->access_mutex);
	return (is_running);
}

/**
 * @brief Safely checks if the required number of compilations is reached.
 *
 * @param coder Entity whose compilation count is being evaluated
 * @return 1 if target compilation count is reached or exceeded, 0 otherwise
 */
int	coder_reached_compilation_count_thread_safe(t_coder *coder)
{
	int	reached;

	pthread_mutex_lock(&coder->access_mutex);
	reached = 0;
	if (coder->compilation_count >= coder->sim->args.number_of_compiles)
		reached = 1;
	pthread_mutex_unlock(&coder->access_mutex);
	return (reached);
}

/**
 * @brief Safely updates the coder's running status.
 *
 * @param coder Entity whose running state is being updated
 * @param is_running New running status flag to be applied
 */
void	coder_set_running_thread_safe(t_coder *coder, int is_running)
{
	pthread_mutex_lock(&coder->access_mutex);
	coder->is_running = is_running;
	pthread_mutex_unlock(&coder->access_mutex);
}
