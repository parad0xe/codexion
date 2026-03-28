/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:32:38 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "heapq.h"
#include <stddef.h>
#include <stdlib.h>

t_dongle	*dongles_create(size_t count, int dongle_cooldown)
{
	t_dongle	*dongles;
	int			i;

	dongles = malloc(sizeof(t_dongle) * count);
	if (dongles == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		dongles[i].cooldown = dongle_cooldown;
		dongles[i].is_available = 1;
		dongles[i].last_usage = 0;
		dongles[i].queue = heapq_create();
		if (dongles[i].queue == NULL)
		{
			dongles_destroy(&dongles, i);
			return (NULL);
		}
	}
	return (dongles);
}
