/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:50:04 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 17:43:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include "codexion.h"
# include "heapq.h"
# include <pthread.h>
# include <stddef.h>

typedef struct s_dongle
{
	int				is_available;
	size_t			cooldown;
	struct timespec	available_at;
	t_heapq			*queue;
	pthread_cond_t	access_cond;
	int				access_cond_init;
	pthread_mutex_t	access_mutex;
	int				access_mutex_init;
}					t_dongle;

// lifecycle
t_dongle			*dongle_create(t_sim_info *sim);
void				dongle_destroy(t_dongle **dongles, size_t count);

// actions
void				dongle_wait_cooldown(t_dongle *dongle);
void				dongle_acquire_thread_unsafe(t_dongle *dongle);
void				dongle_release_thread_safe(t_dongle *dongle);

// states
size_t				dongle_get_ready_at(t_dongle *dongle);

#endif
