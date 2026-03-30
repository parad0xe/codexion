/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_action_dequeue.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:57:56 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:00:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*heapq;

	heapq = heapq_create();
	custom_assert("it should create a valid heapq", heapq != NULL);
	heapq_enqueue(heapq, (void *)1, 10);
	heapq_enqueue(heapq, (void *)3, 30);
	heapq_enqueue(heapq, (void *)2, 20);
	custom_assert("it should return lowest priority element first [1]",
		heapq_dequeue(heapq) == (void *)1);
	custom_assert("it should return (next lowest element [2]",
		heapq_dequeue(heapq) == (void *)2);
	custom_assert("it should return highest priority element last [3]",
		heapq_dequeue(heapq) == (void *)3);
	custom_assert("it should return NULL when heapq is empty",
		heapq_dequeue(heapq) == NULL);
	heapq_destroy(&heapq);
}
