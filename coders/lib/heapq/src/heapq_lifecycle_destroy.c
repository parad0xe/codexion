/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_lifecycle_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:57:15 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:06:03 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stdlib.h>

/**
 * @brief Frees all allocated memory for the queue and its stored items.
 *
 * @param heapq Pointer to the priority queue to completely destroy
 */
void	heapq_destroy(t_heapq **heapq)
{
	int	i;

	if (*heapq == NULL)
		return ;
	if ((*heapq)->items != NULL)
	{
		i = -1;
		while (++i < (*heapq)->count)
			free((*heapq)->items[i]);
		free((*heapq)->items);
	}
	free(*heapq);
	*heapq = NULL;
}
