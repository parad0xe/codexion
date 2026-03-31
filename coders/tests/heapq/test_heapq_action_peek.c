/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_action_peek.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:02:51 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:20:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

static void	_test_heapq_peek(void)
{
	t_heapq	*heapq;

	test_group("test heapq peek");
	heapq = heapq_create();
	assert_is_not_null("handle valid heapq creation", heapq);
	assert_is_null("handle peek on empty heapq safely", heapq_peek(heapq));
	heapq_enqueue(heapq, (void *)20, 20);
	custom_assert("handle peek on single element",
		heapq_peek(heapq)->data == (void *)20);
	heapq_enqueue(heapq, (void *)10, 10);
	custom_assert("handle peek on highest priority element",
		heapq_peek(heapq)->data == (void *)10);
	heapq_enqueue(heapq, (void *)30, 30);
	custom_assert("handle peek unchanged after lower priority enqueue",
		heapq_peek(heapq)->data == (void *)10);
	heapq_destroy(&heapq);
}

int	main(void)
{
	_test_heapq_peek();
	return (0);
}
