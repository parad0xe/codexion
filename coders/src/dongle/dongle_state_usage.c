/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_state_usage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:48:48 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:24:28 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include <unistd.h>

/**
 * @brief Retrieves the absolute timestamp when the dongle is ready.
 *
 * @param dongle Target dongle to evaluate
 * @return Ready timestamp in milliseconds
 */
size_t	dongle_get_ready_at(t_dongle *dongle)
{
	return (time_convert_timespec_to_ms(&dongle->available_at));
}
