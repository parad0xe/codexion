/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 12:46:46 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

static t_errcode	_coder_init(t_coder *coder, int index, t_dongle *dongles,
		t_args *args)
{
	int	right_dongle_index;

	right_dongle_index = math_absmod(index - 1, args->number_of_coders);
	coder->id = index + 1;
	coder->time_to_burnout = args->time_to_burnout;
	coder->time_to_compile = args->time_to_compile;
	coder->time_to_debug = args->time_to_debug;
	coder->time_to_refactor = args->time_to_refactor;
	coder->number_of_compiles = 0;
	coder->scheduler = args->scheduler;
	coder->left_dongle = &dongles[index];
	coder->right_dongle = NULL;
	if (args->number_of_coders > 1)
		coder->right_dongle = &dongles[right_dongle_index];
	if (pthread_mutex_init(&coder->is_running_mutex, NULL) != 0)
		return (ERR_MUTEX_INIT);
	coder->is_running_mutex_init = 1;
	coder->is_running = 1;
	time_set_abstimeout(&coder->burnout_at, args->time_to_burnout);
	return (0);
}

static t_errcode	_coders_init(t_coder_array *coders, t_dongle *dongles,
		t_args *args)
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
	while (i < args->number_of_coders)
	{
		errcode = _coder_init(&coders->items[i], i, dongles, args);
		if (errcode != 0)
			return (errcode);
		coders->items[i].start_mutex = &coders->start_mutex;
		coders->items[i].start_cond = &coders->start_cond;
		coders->items[i].can_start = &coders->can_start;
		coders->count += 1;
		i++;
	}
	return (0);
}

t_coder_array	*coder_create(t_args *args, t_dongle *dongles)
{
	t_coder_array	*coders;

	if (args == NULL || dongles == NULL)
		return (NULL);
	if (strcmp(args->scheduler, "fifo") != 0 && strcmp(args->scheduler,
			"edf") != 0)
		return (NULL);
	coders = malloc(sizeof(t_coder_array));
	if (coders == NULL)
		return (NULL);
	memset(coders, 0, sizeof(t_coder_array));
	coders->items = malloc(sizeof(t_coder) * args->number_of_coders);
	if (coders->items == NULL)
	{
		coder_destroy(&coders);
		return (NULL);
	}
	if (_coders_init(coders, dongles, args) != 0)
	{
		coder_destroy(&coders);
		return (NULL);
	}
	return (coders);
}
