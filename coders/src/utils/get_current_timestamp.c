/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_timestamp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:57:13 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 14:01:35 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>

size_t	get_current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((size_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
