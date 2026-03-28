/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_manager_pool_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:18:29 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 10:41:48 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "dongle.h"
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static t_errcode	_init(t_dongle_manager_pool *pool, size_t dongle_count,
		int cooldown)
{
	t_errcode	errcode;

	errcode = pthread_mutex_init(&pool->shared_mutex, NULL);
	if (errcode != 0)
		return (ERR_MUTEX_INIT);
	pool->count = dongle_count;
	pool->dongles = dongles_create(dongle_count, cooldown);
	if (pool->dongles == NULL)
		return (ERR_DONGLE_MALLOC);
	pool->managers = dongle_managers_create(&pool->shared_mutex, pool->dongles,
			dongle_count, cooldown);
	if (pool->managers == NULL)
		return (ERR_DONGLE_MANAGER_MALLOC);
	return (0);
}

t_dongle_manager_pool	*dmp_create(size_t dongle_count, int cooldown)
{
	t_dongle_manager_pool	*pool;
	t_errcode				errcode;

	pool = malloc(sizeof(t_dongle_manager_pool));
	if (pool == NULL)
		return (NULL);
	memset(pool, 0, sizeof(t_dongle_manager_pool));
	errcode = _init(pool, dongle_count, cooldown);
	if (errcode != 0)
	{
		dmp_destroy(&pool);
		return (NULL);
	}
	return (pool);
}
