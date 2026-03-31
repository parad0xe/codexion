/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:52:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 12:46:07 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_H
# define HEAPQ_H

# include "codexion.h"
# include <stddef.h>

typedef struct s_heapq_data
{
	void			*data;
	size_t			priority;
}					t_heapq_data;

typedef struct s_heapq
{
	t_heapq_data	**items;
	int				capacity;
	int				count;
}					t_heapq;

// lifecycle
t_heapq				*heapq_create(void);
void				heapq_destroy(t_heapq **heapq);

// actions
t_errcode			heapq_enqueue(t_heapq *heapq, void *data, size_t priority);
void				*heapq_dequeue(t_heapq *heapq);
t_heapq_data		*heapq_peek(t_heapq *heapq);

// utils
void				heapq_debug(t_heapq *heapq);

#endif
