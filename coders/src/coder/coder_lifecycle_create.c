/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:22:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Initializes a single coder entity with its specific attributes.
 *
 * @param coder Pointer to the individual coder structure to initialize
 * @param index Numerical position of the coder used to assign its ID
 * @param sim Global simulation information and configuration
 * @param dongles Array of shared dongle resources
 * @return 0 on success, error code otherwise
 */
static t_errcode	_coder_init(t_coder *coder, int index, t_sim_info *sim,
		t_dongle *dongles)
{
	int	right_dongle_index;

	right_dongle_index = math_absmod(index - 1, sim->args.number_of_coders);
	coder->id = index + 1;
	coder->compilation_count = 0;
	coder->left_dongle = &dongles[index];
	coder->right_dongle = NULL;
	if (sim->args.number_of_coders > 1)
		coder->right_dongle = &dongles[right_dongle_index];
	if (pthread_mutex_init(&coder->is_running_mutex, NULL) != 0)
		return (ERR_MUTEX_INIT);
	coder->is_running_mutex_init = 1;
	coder->is_running = 1;
	time_set_abstimeout(&coder->burnout_at, sim->args.time_to_burnout);
	return (0);
}

/**
 * @brief Initializes the array of coders and their shared synchronization.
 *
 * @param coders Array structure containing all coder entities
 * @param sim Global simulation information and configuration
 * @param dongles Array of shared dongle resources
 * @return 0 on success, error code otherwise
 */
static t_errcode	_coders_init(t_coder_array *coders, t_sim_info *sim,
		t_dongle *dongles)
{
	size_t		i;
	t_errcode	errcode;

	coders->count = 0;
	if (pthread_mutex_init(&coders->start_mutex, NULL) != 0)
		return (ERR_MUTEX_INIT);
	coders->start_mutex_init = 1;
	if (pthread_cond_init(&coders->start_cond, NULL) != 0)
		return (ERR_COND_INIT);
	coders->start_cond_init = 1;
	i = 0;
	while (i < sim->args.number_of_coders)
	{
		errcode = _coder_init(&coders->items[i], i, sim, dongles);
		if (errcode != 0)
			return (errcode);
		coders->items[i].start_mutex = &coders->start_mutex;
		coders->items[i].start_cond = &coders->start_cond;
		coders->items[i].can_start = &coders->can_start;
		coders->items[i].sim = sim;
		coders->count += 1;
		i++;
	}
	return (0);
}

/**
 * @brief Allocates and initializes the full coder array for the simulation.
 *
 * @param sim Global simulation information and configuration
 * @param dongles Array of shared dongle resources
 * @return Pointer to the allocated coder array, or NULL on failure
 */
t_coder_array	*coder_create(t_sim_info *sim, t_dongle *dongles)
{
	t_coder_array	*coders;

	if (sim == NULL || dongles == NULL)
		return (NULL);
	if (strcmp(sim->args.scheduler, "fifo") != 0
		&& strcmp(sim->args.scheduler, "edf") != 0)
		return (NULL);
	coders = malloc(sizeof(t_coder_array));
	if (coders == NULL)
		return (NULL);
	memset(coders, 0, sizeof(t_coder_array));
	coders->items = malloc(sizeof(t_coder) * sim->args.number_of_coders);
	if (coders->items == NULL)
	{
		coder_destroy(&coders);
		return (NULL);
	}
	if (_coders_init(coders, sim, dongles) != 0)
	{
		coder_destroy(&coders);
		return (NULL);
	}
	return (coders);
}
