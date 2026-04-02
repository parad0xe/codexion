/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_action_dequeue.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:57:56 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:45:23 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

static void	_test_heapq_dequeue(void)
{
	t_heapq	*heapq;

	test_group("test heapq dequeue");
	heapq = heapq_create();
	assert_is_not_null("handle valid heapq creation", heapq);
	heapq_enqueue(heapq, (void *)1, 10);
	heapq_enqueue(heapq, (void *)3, 30);
	heapq_enqueue(heapq, (void *)2, 20);
	custom_assert("handle lowest priority element first",
		heapq_dequeue(heapq) == (void *)1);
	custom_assert("handle next lowest priority element",
		heapq_dequeue(heapq) == (void *)2);
	custom_assert("handle highest priority element last",
		heapq_dequeue(heapq) == (void *)3);
	assert_is_null("handle empty heapq safely", heapq_dequeue(heapq));
	heapq_destroy(&heapq);
}

int	main(void)
{
	_test_heapq_dequeue();
	test_group("test null parameters");
	assert_is_null("handle null heapq pointer", heapq_dequeue(NULL));
	return (0);
}
