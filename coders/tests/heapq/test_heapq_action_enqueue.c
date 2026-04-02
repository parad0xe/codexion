/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_action_enqueue.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:56:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:43:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "heapq.h"
#include "test.h"

static void	_test_heapq_enqueue(void)
{
	t_heapq	*heapq;

	test_group("test heapq enqueue");
	heapq = heapq_create();
	assert_is_not_null("handle valid heapq creation", heapq);
	heapq_enqueue(heapq, (void *)10, 20);
	custom_assert("handle element with priority 20 at top",
		heapq->items[0]->data == (void *)10);
	heapq_enqueue(heapq, (void *)30, 10);
	custom_assert("handle element with priority 10 moved to top",
		heapq->items[0]->data == (void *)30);
	heapq_enqueue(heapq, (void *)20, 30);
	custom_assert("handle element with priority 10 kept at top",
		heapq->items[0]->data == (void *)30);
	heapq_destroy(&heapq);
}

int	main(void)
{
	_test_heapq_enqueue();
	test_group("test null parameters");
	custom_assert("handle null heapq pointer", heapq_enqueue(NULL, (void *)10,
			20) == ERR_HEAPQ_NULL);
	return (0);
}
