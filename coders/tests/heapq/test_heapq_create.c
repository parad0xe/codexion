/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:53:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:42:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*heap;

	heap = heapq_create();
	custom_assert("it should create a valid heap", heap != NULL);
	custom_assert("it should initialize the internal items",
		heap->items != NULL);
	custom_assert("it should start with count 0", heap->count == 0);
	custom_assert("it should start with capacity 2", heap->capacity == 2);
	heapq_destroy(&heap);
	custom_assert("it should set heap to NULL after destroy", heap == NULL);
	return (0);
}
