/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heapq_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:55:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:01:01 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "test.h"

int	main(void)
{
	t_heapq	*heapq;

	heapq = heapq_create();
	custom_assert("it should create a valid heapq", heapq != NULL);
	custom_assert("it should start with count 0", heapq->count == 0);
	heapq_destroy(&heapq);
	custom_assert("it should set heapq to NULL after destroy", heapq == NULL);
	return (0);
}
