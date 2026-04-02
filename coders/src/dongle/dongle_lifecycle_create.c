/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_lifecycle_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 18:01:01 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "dongle.h"
#include "heapq.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initializes a single dongle and its priority queue.
 *
 * @param dongle Target dongle structure to initialize
 * @param cooldown Cooldown duration assigned to the dongle
 * @return 0 on success, error code otherwise
 */
t_errcode	_dongle_init(t_dongle *dongle, int cooldown)
{
	t_errcode	errcode;

	errcode = pthread_mutex_init(&dongle->access_mutex, NULL);
	if (errcode != 0)
		return (ERR_DONGLE_MUTEX_INIT);
	dongle->access_mutex_init = 1;
	errcode = pthread_cond_init(&dongle->access_cond, NULL);
	if (errcode != 0)
		return (ERR_DONGLE_COND_INIT);
	dongle->access_cond_init = 1;
	dongle->cooldown = cooldown;
	dongle->is_available = 1;
	time_set_abstimeout(&dongle->available_at, 0);
	dongle->queue = heapq_create();
	if (dongle->queue == NULL)
		return (ERR_HEAPQ_MALLOC);
	return (0);
}

/**
 * @brief Allocates and initializes the full array of dongles.
 *
 * @param sim Global simulation information and configuration
 * @return Pointer to the allocated array or NULL on failure
 */
t_dongle	*dongle_create(t_sim_info *sim)
{
	t_dongle	*dongles;
	size_t		i;
	t_errcode	errcode;

	dongles = malloc(sizeof(t_dongle) * sim->args.number_of_coders);
	if (dongles == NULL)
	{
		sim->errcode = ERR_DONGLE_MALLOC;
		return (NULL);
	}
	memset(dongles, 0, sizeof(t_dongle) * sim->args.number_of_coders);
	i = 0;
	while (i < sim->args.number_of_coders)
	{
		errcode = _dongle_init(&dongles[i], sim->args.dongle_cooldown);
		if (errcode != 0)
		{
			sim->errcode = errcode;
			dongle_destroy(&dongles, i);
			return (NULL);
		}
		i++;
	}
	return (dongles);
}
