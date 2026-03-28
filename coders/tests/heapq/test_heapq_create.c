/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:53:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:00:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*heapq;

	heapq = heapq_create();
	custom_assert("it should create a valid heapq", heapq != NULL);
	custom_assert("it should initialize the internal items",
		heapq->items != NULL);
	custom_assert("it should start with count 0", heapq->count == 0);
	custom_assert("it should start with capacity 2", heapq->capacity == 2);
	heapq_destroy(&heapq);
	custom_assert("it should set heapq to NULL after destroy", heapq == NULL);
	return (0);
}
