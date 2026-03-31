/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:50:04 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 15:15:15 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

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
t_dongle			*dongle_create(size_t count, int dongle_cooldown);
void				dongle_destroy(t_dongle **dongles, size_t count);

// actions
void				dongle_wait_cooldown(t_dongle *dongle);
void				dongle_thread_unsafe_acquire(t_dongle *dongle);
void				dongle_thread_safe_release(t_dongle *dongle);

// states
size_t				dongle_get_ready_at(t_dongle *dongle);

#endif
