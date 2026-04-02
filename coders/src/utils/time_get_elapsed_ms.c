/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_get_elapsed_ms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:35:08 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:26:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Calculates the elapsed time in milliseconds since a timestamp.
 *
 * @param ts Starting timestamp to compare against the current time
 * @return Elapsed time in milliseconds
 */
size_t	time_get_elapsed_ms(struct timespec *ts)
{
	return (time_get_current_ms() - time_convert_timespec_to_ms(ts));
}
