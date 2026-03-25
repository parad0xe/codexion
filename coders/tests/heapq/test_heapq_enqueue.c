/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_enqueue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:56:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 21:59:25 by nlallema         ###   ########lyon.fr   */
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
	custom_assert(h != NULL);
	heapq_enqueue(h, (void *)10, 20);
	custom_assert(h->queue[0]->data == (void *)10);
	heapq_enqueue(h, (void *)30, 10);
	custom_assert(h->queue[0]->data == (void *)30);
	heapq_enqueue(h, (void *)20, 30);
	custom_assert(h->queue[0]->data == (void *)30);
	heapq_destroy(&h);
	print_test_ok();
}
