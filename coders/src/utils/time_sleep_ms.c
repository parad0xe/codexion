/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sleep_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:35:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:27:04 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Suspends execution using micro-pauses until duration is reached.
 *
 * @param ms Amount of milliseconds to sleep
 */
void	time_sleep_ms(size_t ms)
{
	size_t	start;

	start = time_get_current_ms();
	while (time_get_current_ms() - start < ms)
		usleep(500);
}
