/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_get_current_ms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:35:01 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:26:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Retrieves the current system time converted into milliseconds.
 *
 * @return Current timestamp in milliseconds
 */
size_t	time_get_current_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}
