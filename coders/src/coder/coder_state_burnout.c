/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_burnout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:12:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:21:33 by nlallema         ###   ########lyon.fr   */
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
size_t	coder_get_burnout_at(t_coder *coder)
{
	return (time_convert_timespec_to_ms(&coder->burnout_at));
}

/**
 * @brief Checks if the current time exceeds the coder's burnout limit.
 *
 * @param coder Entity to evaluate for a burnout state
 * @return 1 if burnout occurred, 0 otherwise
 */
int	coder_has_burnout(t_coder *coder)
{
	int	has_burnout;

	has_burnout = time_get_current_ms() >= coder_get_burnout_at(coder);
	return (has_burnout);
}
