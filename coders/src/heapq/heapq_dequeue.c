/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:13:38 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:10:35 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stdlib.h>

static int	_heapq_heapify_down_try_swap(t_heapq *heapq, int *index)
{
	t_heapq_data	*current;
	int				left_idx;
	int				right_idx;
	int				target_idx;

	current = heapq->items[*index];
	left_idx = (*index) * 2 + 1;
	right_idx = (*index) * 2 + 2;
	target_idx = left_idx;
	if (heapq->items[left_idx]->priority > heapq->items[right_idx]->priority)
		target_idx = right_idx;
	if (current->priority < heapq->items[target_idx]->priority)
		return (0);
	heapq->items[*index] = heapq->items[target_idx];
	heapq->items[target_idx] = current;
	*index = target_idx;
	return (1);
}

static void	_heapq_heapify_down(t_heapq *heapq)
{
	int	current_idx;
	int	swap_success;

	if (heapq->count > 1)
	{
		heapq->items[0] = heapq->items[heapq->count - 1];
		heapq->items[heapq->count - 1] = NULL;
		heapq->count -= 1;
		current_idx = 0;
		while (current_idx * 2 + 2 < heapq->count)
		{
			swap_success = _heapq_heapify_down_try_swap(heapq, &current_idx);
			if (swap_success == 0)
				break ;
		}
	}
	else
		heapq->count -= 1;
}

void	*heapq_dequeue(t_heapq *heapq)
{
	t_heapq_data	*heapq_data;
	void			*data;

	if (heapq->count == 0)
		return (NULL);
	heapq_data = heapq->items[0];
	_heapq_heapify_down(heapq);
	data = heapq_data->data;
	free(heapq_data);
	heapq_data = NULL;
	return (data);
}
