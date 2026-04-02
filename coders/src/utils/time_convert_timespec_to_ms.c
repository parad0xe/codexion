/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_convert_timespec_to_ms.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:34:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:27:14 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Converts a timespec structure value into milliseconds.
 *
 * @param ts Target timespec structure to be converted
 * @return The converted time in milliseconds
 */
size_t	time_convert_timespec_to_ms(struct timespec *ts)
{
	size_t	milliseconds;

	milliseconds = ((size_t)ts->tv_sec * 1000) + ((size_t)ts->tv_nsec
			/ 1000000);
	return (milliseconds);
}
