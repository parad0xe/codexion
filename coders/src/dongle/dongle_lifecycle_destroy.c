/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_lifecycle_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:24:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "heapq.h"
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Frees all allocated memory and mutexes for the dongles.
 *
 * @param dongles Pointer to the array of dongles to destroy
 * @param count Number of initialized dongles in the array
 */
void	dongle_destroy(t_dongle **dongles, size_t count)
{
	size_t	i;

	if (*dongles == NULL)
		return ;
	i = 0;
	while (i < count)
	{
		if ((*dongles)[i].access_mutex_init)
			pthread_mutex_destroy(&(*dongles)[i].access_mutex);
		if ((*dongles)[i].access_cond_init)
			pthread_cond_destroy(&(*dongles)[i].access_cond);
		if ((*dongles)[i].queue != NULL)
			heapq_destroy(&(*dongles)[i].queue);
		i++;
	}
	free(*dongles);
	(*dongles) = NULL;
}
