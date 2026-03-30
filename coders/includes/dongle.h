/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:50:04 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:43:05 by nlallema         ###   ########lyon.fr   */
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
	size_t			last_usage;
	t_heapq			*queue;
	pthread_cond_t	access_cond;
	int				access_cond_init;
	pthread_mutex_t	access_mutex;
	int				access_mutex_init;
}					t_dongle;

t_dongle			*dongle_create(size_t count, int dongle_cooldown);
void				dongle_destroy(t_dongle **dongles, size_t count);

size_t				dongle_get_ready_timestamp(t_dongle *dongle);

#endif
