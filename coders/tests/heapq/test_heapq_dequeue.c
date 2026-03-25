/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_dequeue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:57:56 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 21:59:18 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_heapq	*h;

	print_test_start("heapq dequeue");
	h = heapq_create();
	custom_assert(h != NULL);
	heapq_enqueue(h, (void *)1, 10);
	heapq_enqueue(h, (void *)3, 30);
	heapq_enqueue(h, (void *)2, 20);
	custom_assert(heapq_dequeue(h) == (void *)1);
	custom_assert(heapq_dequeue(h) == (void *)2);
	custom_assert(heapq_dequeue(h) == (void *)3);
	custom_assert(heapq_dequeue(h) == NULL);
	heapq_destroy(&h);
	print_test_ok();
}
