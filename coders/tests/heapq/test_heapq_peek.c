/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_peek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:02:51 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 16:04:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*h;

	h = heapq_create();
	custom_assert("it should create a valid heap", h != NULL);
	custom_assert("it should return NULL when heap is empty",
		heapq_peek(h) == NULL);
	heapq_enqueue(h, (void *)20, 20);
	custom_assert("it should return the only element",
		heapq_peek(h) == (void *)20);
	heapq_enqueue(h, (void *)10, 10);
	custom_assert("it should return the highest priority element",
		heapq_peek(h) == (void *)10);
	heapq_enqueue(h, (void *)30, 30);
	custom_assert("it should still return the highest priority element",
		heapq_peek(h) == (void *)10);
	heapq_destroy(&h);
	return (0);
}
