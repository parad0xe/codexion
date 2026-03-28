/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_peek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:02:51 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:01:27 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*heapq;

	heapq = heapq_create();
	custom_assert("it should create a valid heapq", heapq != NULL);
	custom_assert("it should return NULL when heapq is empty",
		heapq_peek(heapq) == NULL);
	heapq_enqueue(heapq, (void *)20, 20);
	custom_assert("it should return the only element",
		heapq_peek(heapq) == (void *)20);
	heapq_enqueue(heapq, (void *)10, 10);
	custom_assert("it should return the highest priority element",
		heapq_peek(heapq) == (void *)10);
	heapq_enqueue(heapq, (void *)30, 30);
	custom_assert("it should still return the highest priority element",
		heapq_peek(heapq) == (void *)10);
	heapq_destroy(&heapq);
	return (0);
}
