/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:07:03 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:50:53 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void	time_sleep_ms(size_t ms)
{
	usleep(ms * 1000);
}

size_t	time_get_current_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}

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

size_t	time_convert_timespec_to_ms(struct timespec *ts)
{
	size_t	milliseconds;

	milliseconds = ((size_t)ts->tv_sec * 1000) + ((size_t)ts->tv_nsec
			/ 1000000);
	return (milliseconds);
}
