/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongles_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:35:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:42:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"
#include <stddef.h>

static void	_test_dongles(t_dongle *dongles, size_t size, int cooldown)
{
	int	i;

	i = -1;
	while (i < size)
	{
		custom_assert("it should create a valid array of dongles",
			dongles != NULL);
		custom_assert("it should initialize the correct cooldown",
			dongles[i].cooldown == cooldown);
		custom_assert("it should set availability to 1",
			dongles[i].is_available == 1);
		custom_assert("it should initialize last_usage to 0",
			dongles[i].last_usage == 0);
		custom_assert("it should create a valid heapq for the dongle",
			dongles[i].queue != NULL);
	}
}

int	main(void)
{
	t_dongle	*dongles;
	size_t		size;
	int			cooldown;
	int			i;

	size = 3;
	cooldown = 15;
	dongles = dongles_create(size, cooldown);
	_test_dongles(dongles, size, cooldown);
	dongles_destroy(&dongles, size);
	return (0);
}
