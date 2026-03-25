/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_enqueue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:56:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 22:41:37 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_heapq	*h;

	print_test_start("heapq enqueue");
	h = heapq_create();
	custom_assert("it should create a valid heap", h != NULL);
	heapq_enqueue(h, (void *)10, 20);
	custom_assert("it should have element with priority 20 at top",
		h->queue[0]->data == (void *)10);
	heapq_enqueue(h, (void *)30, 10);
	custom_assert("it should move element with priority 10 to top",
		h->queue[0]->data == (void *)30);
	heapq_enqueue(h, (void *)20, 30);
	custom_assert("it should keep element with priority 10 at top",
		h->queue[0]->data == (void *)30);
	heapq_destroy(&h);
	print_test_ok();
}
