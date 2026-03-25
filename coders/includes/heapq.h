/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:52:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 19:37:22 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_H
# define HEAPQ_H

# include "codexion.h"
# include <stddef.h>

# define ERR_HEAPQ_MALLOC 10

typedef struct s_heapq_data
{
	void			*data;
	int				priority;
}					t_heapq_data;

typedef struct s_heapq
{
	t_heapq_data	**queue;
	int				capacity;
	int				size;
}					t_heapq;

t_heapq				*heapq_create(void);
t_errcode			heapq_enqueue(t_heapq *heapq, void *data, int priority);
void				*heapq_dequeue(t_heapq *heapq);
void				*heapq_peek(t_heapq *heapq);
void				heapq_destroy(t_heapq **heapq);
void				heapq_debug(t_heapq *heapq);

#endif
