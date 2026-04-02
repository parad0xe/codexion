/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_lifecycle_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:53:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:16:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

static void	_test_heapq_create(void)
{
	t_heapq	*heapq;

	test_group("test heapq create");
	heapq = heapq_create();
	assert_is_not_null("handle valid heapq creation", heapq);
	assert_is_not_null("handle internal items initialization", heapq->items);
	custom_assert("handle expected count initialization", heapq->count == 0);
	custom_assert("handle expected capacity initialization",
		heapq->capacity == 2);
	heapq_destroy(&heapq);
	assert_is_null("handle pointer reset to null after destroy", heapq);
}

int	main(void)
{
	_test_heapq_create();
	return (0);
}
