/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_action_peek.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:59:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 20:21:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"

t_heapq_data	*heapq_peek(t_heapq *heapq)
{
	if (heapq == NULL || heapq->count == 0)
		return (NULL);
	return (heapq->items[0]);
}
