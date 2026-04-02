/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_set_abstimeout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:35:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:26:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Computes an absolute timeout in the future from current time.
 *
 * @param ts Target timespec structure to be updated
 * @param timeout Amount of milliseconds to add to the current time
 */
void	time_set_abstimeout(struct timespec *ts, size_t timeout)
{
	struct timeval	tv;
	size_t			usec_total;

	gettimeofday(&tv, NULL);
	ts->tv_sec = (size_t)tv.tv_sec + (timeout / 1000);
	usec_total = (size_t)tv.tv_usec + ((timeout % 1000) * 1000);
	if (usec_total >= 1000000)
	{
		ts->tv_sec++;
		usec_total -= 1000000;
	}
	ts->tv_nsec = usec_total * 1000;
}
