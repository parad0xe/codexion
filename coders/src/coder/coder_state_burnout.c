/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_burnout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:12:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:35:13 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"

/**
 * @brief Retrieves the absolute timestamp of the coder's burnout limit.
 *
 * @param coder Entity whose burnout limit is being checked
 * @return Timestamp in milliseconds when burnout occurs
 */
size_t	coder_get_burnout_at_thread_safe(t_coder *coder)
{
	size_t	burnout_at;

	pthread_mutex_lock(&coder->access_mutex);
	burnout_at = time_convert_timespec_to_ms(&coder->burnout_at);
	pthread_mutex_unlock(&coder->access_mutex);
	return (burnout_at);
}

/**
 * @brief Resets the absolute timestamp of the coder's burnout limit.
 *
 * Updates the burnout limit in a thread-safe manner based on the 
 * time_to_burnout parameter defined in the simulation arguments.
 *
 * @param coder Entity whose burnout limit is being reset
 */
void	coder_reset_burnout_at_thread_safe(t_coder *coder)
{
	pthread_mutex_lock(&coder->access_mutex);
	time_set_abstimeout(&coder->burnout_at, coder->sim->args.time_to_burnout);
	pthread_mutex_unlock(&coder->access_mutex);
}

/**
 * @brief Checks if the current time exceeds the coder's burnout limit.
 *
 * @param coder Entity to evaluate for a burnout state
 * @return 1 if burnout occurred, 0 otherwise
 */
int	coder_has_burnout_thread_safe(t_coder *coder)
{
	int		has_burnout;
	size_t	burnout_at_ms;

	burnout_at_ms = coder_get_burnout_at_thread_safe(coder);
	has_burnout = time_get_current_ms() >= burnout_at_ms;
	return (has_burnout);
}
