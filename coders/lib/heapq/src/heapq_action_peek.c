/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_action_peek.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:59:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:06:22 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"

/**
 * @brief Retrieves the highest priority element without removing it.
 *
 * @param heapq Target priority queue to peek into
 * @return Pointer to the data with the highest priority
 */
t_heapq_data	*heapq_peek(t_heapq *heapq)
{
	if (heapq == NULL || heapq->count == 0)
		return (NULL);
	return (heapq->items[0]);
}
