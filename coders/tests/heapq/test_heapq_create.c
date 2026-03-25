/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:53:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 21:59:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_heapq	*heap;

	print_test_start("heapq create");
	heap = heapq_create();
	custom_assert(heap != NULL);
	custom_assert(heap->queue != NULL);
	custom_assert(heap->size == 0);
	custom_assert(heap->capacity > 0);
	heapq_destroy(&heap);
	custom_assert(heap == NULL);
	print_test_ok();
	return (0);
}
