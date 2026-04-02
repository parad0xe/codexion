/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:04:55 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:11:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stdio.h>

/**
 * @brief Recursively prints the heap tree nodes with indentation.
 *
 * @param heapq Target priority queue to visualize
 * @param index Current node position in the array
 * @param depth Current depth level for indentation
 */
static void	_heapq_print_tree(t_heapq *heapq, int index, int depth)
{
	int	indent;
	int	left_index;
	int	right_index;

	if (heapq == NULL || index >= heapq->count)
		return ;
	left_index = 2 * index + 1;
	right_index = 2 * index + 2;
	_heapq_print_tree(heapq, right_index, depth + 1);
	indent = 0;
	while (indent++ < depth)
		printf("        ");
	printf("- [%d] prio(%ld) p(%p)\n", index, heapq->items[index]->priority,
		heapq->items[index]->data);
	_heapq_print_tree(heapq, left_index, depth + 1);
}

/**
 * @brief Prints a visual representation of the heap tree to standard output.
 *
 * @param heapq Priority queue to visualize
 */
void	heapq_debug(t_heapq *heapq)
{
	if (!heapq)
		return ;
	printf("\nSize: %d / Cap: %d\n", heapq->count, heapq->capacity);
	printf("--- Visual Tree ---\n");
	_heapq_print_tree(heapq, 0, 0);
	printf("-------------------\n");
}
