/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_managers_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:48:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 10:13:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

t_dongle_manager	*dongle_managers_create(pthread_mutex_t *mutex,
		t_dongle *dongles, size_t dongle_count, int dongle_cooldown)
{
	t_dongle_manager	*managers;
	int					i;

	managers = malloc(sizeof(t_dongle_manager) * dongle_count);
	if (managers == NULL)
		return (NULL);
	memset(managers, 0, sizeof(t_dongle_manager) * dongle_count);
	i = -1;
	while (++i < dongle_count)
	{
		managers[i].shared_mutex = mutex;
		managers[i].left_dongle = &dongles[i];
		managers[i].right_dongle = NULL;
		if (dongle_count > 1)
			managers[i].right_dongle = &dongles[absmod(i - 1, dongle_count)];
	}
	return (managers);
}
