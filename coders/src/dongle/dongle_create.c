/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:43:27 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "dongle.h"
#include "heapq.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

t_errcode	_dongle_init(t_dongle *dongle, int cooldown)
{
	t_errcode	errcode;

	errcode = pthread_mutex_init(&dongle->access_mutex, NULL);
	if (errcode != 0)
		return (ERR_MUTEX_INIT);
	dongle->access_mutex_init = 1;
	errcode = pthread_cond_init(&dongle->access_cond, NULL);
	if (errcode != 0)
		return (ERR_COND_INIT);
	dongle->access_cond_init = 1;
	dongle->cooldown = cooldown;
	dongle->is_available = 1;
	dongle->last_usage = 0;
	dongle->queue = heapq_create();
	if (dongle->queue == NULL)
		return (ERR_HEAPQ_MALLOC);
	return (0);
}

t_dongle	*dongle_create(size_t count, int cooldown)
{
	t_dongle	*dongles;
	size_t		i;
	t_errcode	errcode;

	dongles = malloc(sizeof(t_dongle) * count);
	if (dongles == NULL)
		return (NULL);
	memset(dongles, 0, sizeof(t_dongle) * count);
	i = 0;
	while (i < count)
	{
		errcode = _dongle_init(&dongles[i], cooldown);
		if (errcode != 0)
		{
			dongle_destroy(&dongles, i);
			return (NULL);
		}
		i++;
	}
	return (dongles);
}
