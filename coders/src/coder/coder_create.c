/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:43:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"
#include "utils.h"
#include <stdlib.h>

static void	_coder_init(t_coder *coder, int id, t_dongle *dongles, t_args *args)
{
	coder->id = id;
	coder->time_to_burnout = args->time_to_burnout;
	coder->time_to_compile = args->time_to_compile;
	coder->time_to_debug = args->time_to_debug;
	coder->time_to_refactor = args->time_to_refactor;
	coder->number_of_compiles = args->number_of_compiles;
	coder->scheduler = args->scheduler;
	coder->left_dongle = &dongles[id];
	coder->right_dongle = NULL;
	if (args->number_of_coders > 1)
		coder->right_dongle = &dongles[absmod(id - 1, args->number_of_coders)];
	set_absolute_timeout(&coder->burnout_at, args->time_to_burnout);
}

t_coder	*coder_create(t_args *args, t_dongle *dongles,
		pthread_mutex_t *start_mutex)
{
	t_coder	*coders;
	size_t	i;
	size_t	current_timestamp;

	if (args == NULL || dongles == NULL)
		return (NULL);
	coders = malloc(sizeof(t_coder) * args->number_of_coders);
	if (coders == NULL)
		return (NULL);
	i = 0;
	current_timestamp = get_current_timestamp();
	while (i < args->number_of_coders)
	{
		_coder_init(&coders[i], i, dongles, args);
		coders[i].last_compile_start = current_timestamp;
		coders[i].start_mutex = start_mutex;
		i++;
	}
	return (coders);
}
