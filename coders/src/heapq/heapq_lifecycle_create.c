/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_lifecycle_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:54:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:10:18 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

t_heapq	*heapq_create(void)
{
	t_heapq	*heapq;

	heapq = malloc(sizeof(t_heapq));
	if (heapq == NULL)
		return (NULL);
	heapq->count = 0;
	heapq->capacity = 2;
	heapq->items = malloc(sizeof(t_heapq_data *) * heapq->capacity);
	if (heapq->items == NULL)
	{
		heapq_destroy(&heapq);
		return (NULL);
	}
	memset(heapq->items, 0, sizeof(t_heapq_data *));
	return (heapq);
}
