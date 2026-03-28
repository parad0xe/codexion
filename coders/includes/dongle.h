/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:50:04 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:23:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include "heapq.h"
# include <pthread.h>
# include <stddef.h>

typedef struct s_dongle
{
	int					is_available;
	int					cooldown;
	int					last_usage;
	t_heapq				*queue;
}						t_dongle;

// demander l'access au manager
// le manager lock le shared mutex
// le manager check pour chaque dongle (left / right):
// - si la liste d'attente du dongle est vide
// - si le dongle est disponible
// - si le dongle est utilisable
typedef struct s_dongle_manager
{
	pthread_mutex_t		*shared_mutex;
	t_dongle			*left_dongle;
	t_dongle			*right_dongle;
}						t_dongle_manager;

typedef struct s_dongle_manager_pool
{
	pthread_mutex_t		shared_mutex;
	t_dongle_manager	*managers;
	t_dongle			*dongles;
	size_t				count;
}						t_dongle_manager_pool;

t_dongle_manager_pool	*dmp_create(size_t dongle_count, int cooldown);
void					dmp_destroy(t_dongle_manager_pool **pool);

t_dongle_manager		*dongle_managers_create(pthread_mutex_t *mutex,
							t_dongle *dongles, size_t dongle_count);
void					dongle_managers_destroy(t_dongle_manager **managers);

t_dongle				*dongles_create(size_t count, int dongle_cooldown);
void					dongles_destroy(t_dongle **dongles, size_t count);

#endif
