/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:04:55 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 20:05:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stdio.h>

static void	_heapq_print_tree(t_heapq *heapq, int index, int depth)
{
	int	indent;
	int	left_idx;
	int	right_idx;

	if (index >= heapq->size)
		return ;
	left_idx = 2 * index + 1;
	right_idx = 2 * index + 2;
	_heapq_print_tree(heapq, right_idx, depth + 1);
	indent = 0;
	while (indent++ < depth)
		printf("        ");
	printf("- [%d] prio(%d) p(%p)\n", index, heapq->queue[index]->priority,
		heapq->queue[index]->data);
	_heapq_print_tree(heapq, left_idx, depth + 1);
}

void	heapq_debug(t_heapq *heapq)
{
	if (!heapq)
		return ;
	printf("\nSize: %d / Cap: %d\n", heapq->size, heapq->capacity);
	printf("--- Visual Tree ---\n");
	_heapq_print_tree(heapq, 0, 0);
	printf("-------------------\n");
}
