/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_absolute_timeout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:07:03 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 14:12:07 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <time.h>

void	set_absolute_timeout(struct timespec *ts, size_t timeout)
{
	struct timeval	tv;
	long			usec_total;

	gettimeofday(&tv, NULL);
	ts->tv_sec = tv.tv_sec + (timeout / 1000);
	usec_total = tv.tv_usec + ((timeout % 1000) * 1000);
	if (usec_total >= 1000000)
	{
		ts->tv_sec++;
		usec_total -= 1000000;
	}
	ts->tv_nsec = usec_total * 1000;
}
