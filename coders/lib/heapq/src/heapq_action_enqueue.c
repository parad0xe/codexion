/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_action_enqueue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:06:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:09:45 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "heapq.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocates and initializes a new heap node.
 *
 * @param data Generic pointer to the item to store
 * @param priority Weight value used to sort the queue
 * @return Pointer to the allocated node or NULL
 */
static t_heapq_data	*_heapq_create_data(void *data, size_t priority)
{
	t_heapq_data	*heapq_data;

	heapq_data = malloc(sizeof(t_heapq_data));
	if (heapq_data == NULL)
		return (NULL);
	heapq_data->data = data;
	heapq_data->priority = priority;
	return (heapq_data);
}

/**
 * @brief Doubles the capacity of the heap array.
 *
 * @param heapq Target priority queue to expand
 * @return 0 on success, error code otherwise
 */
static t_errcode	_heapq_more_space(t_heapq *heapq)
{
	t_heapq_data	**new_queue;
	int				new_capacity;
	int				i;

	new_capacity = heapq->capacity * 2;
	new_queue = malloc(sizeof(t_heapq_data *) * new_capacity);
	if (new_queue == NULL)
		return (ERR_HEAPQ_MALLOC);
	i = -1;
	while (++i < heapq->count)
		new_queue[i] = heapq->items[i];
	free(heapq->items);
	heapq->items = new_queue;
	heapq->capacity = new_capacity;
	return (0);
}

/**
 * @brief Checks capacity and expands the array if necessary.
 *
 * @param heapq Target priority queue to check
 * @return 0 on success, error code otherwise
 */
static t_errcode	_heapq_ensure_has_capacity(t_heapq *heapq)
{
	if (heapq->count + 1 > heapq->capacity)
		return (_heapq_more_space(heapq));
	return (0);
}

/**
 * @brief Restores the heap property by moving the last element up.
 *
 * @param heapq Target priority queue to sort
 */
static void	_heapq_heapify_up(t_heapq *heapq)
{
	int				i;
	t_heapq_data	*parent;
	t_heapq_data	*current;
	t_heapq_data	*tmp;

	i = heapq->count - 1;
	while (i >= 0)
	{
		parent = heapq->items[(i - 1) / 2];
		current = heapq->items[i];
		if (current->priority < parent->priority)
		{
			tmp = parent;
			heapq->items[(i - 1) / 2] = current;
			heapq->items[i] = tmp;
			i = (i - 1) / 2;
			continue ;
		}
		break ;
	}
}

/**
 * @brief Inserts new data into the priority queue and restores heap order.
 *
 * The element with the lowest priority value has the highest priority.
 *
 * @param heapq Target priority queue for insertion
 * @param data Generic pointer to the item to store
 * @param priority Weight value used to sort the queue
 * @return 0 on success, error code otherwise
 */
t_errcode	heapq_enqueue(t_heapq *heapq, void *data, size_t priority)
{
	int				errcode;
	t_heapq_data	*heapq_data;

	if (heapq == NULL)
		return (ERR_HEAPQ_NULL);
	heapq_data = _heapq_create_data(data, priority);
	if (heapq_data == NULL)
		return (ERR_HEAPQ_MALLOC);
	errcode = _heapq_ensure_has_capacity(heapq);
	if (errcode != 0)
		return (errcode);
	heapq->items[heapq->count] = heapq_data;
	heapq->count += 1;
	_heapq_heapify_up(heapq);
	return (0);
}
