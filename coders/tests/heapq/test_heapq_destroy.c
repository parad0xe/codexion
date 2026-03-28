/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:55:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:07:03 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*h;

	print_test_start("heapq destroy");
	h = heapq_create();
	custom_assert("it should create a valid heap", h != NULL);
	custom_assert("it should start with count 0", h->count == 0);
	heapq_destroy(&h);
	custom_assert("it should set heap to NULL after destroy", h == NULL);
	print_test_ok();
	return (0);
}
