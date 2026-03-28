/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:20:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "dongle.h"
#include <stdlib.h>

t_coder	*coders_create(t_args *args, t_dongle_manager_pool *pool)
{
	t_coder	*coders;
	size_t	i;

	if (args == NULL || pool == NULL)
		return (NULL);
	if (args->number_of_coders != pool->count)
		return (NULL);
	coders = malloc(sizeof(t_coder) * args->number_of_coders);
	if (coders == NULL)
		return (NULL);
	i = 0;
	while (i < args->number_of_coders)
	{
		coders[i].dongle_manager = &pool->managers[i];
		coders[i].time_to_burnout = args->time_to_burnout;
		coders[i].time_to_compile = args->time_to_compile;
		coders[i].time_to_debug = args->time_to_debug;
		coders[i].time_to_refactor = args->time_to_refactor;
		coders[i].number_of_compiles = args->number_of_compiles;
		i++;
	}
	return (coders);
}
