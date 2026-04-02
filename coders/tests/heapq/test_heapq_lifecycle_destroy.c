/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_lifecycle_destroy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:55:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:17:38 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

static void	_test_heapq_destroy(void)
{
	t_heapq	*heapq;

	test_group("test heapq destroy");
	heapq = heapq_create();
	assert_is_not_null("handle valid heapq creation", heapq);
	custom_assert("handle expected count initialization", heapq->count == 0);
	heapq_destroy(&heapq);
	assert_is_null("handle pointer reset to null after destroy", heapq);
	heapq_destroy(&heapq);
	assert_is_null("handle already null pointer safely", heapq);
}

int	main(void)
{
	_test_heapq_destroy();
	return (0);
}
