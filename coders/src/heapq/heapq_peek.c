/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:59:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 16:01:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"

void	*heapq_peek(t_heapq *heapq)
{
	if (heapq == NULL || heapq->count == 0)
		return (NULL);
	return (heapq->items[0]->data);
}
