/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_lifecycle_create.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:35:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:12:46 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"
#include <stddef.h>
#include <stdio.h>

static void	_test_dongles(t_dongle *dongles, size_t size, int cooldown)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		test_loop_group("test dongle", i);
		custom_assert("handle correct cooldown initialization",
			dongles[i].cooldown == cooldown);
		custom_assert("handle availability initialization to 1",
			dongles[i].is_available == 1);
		assert_is_not_null("handle valid heapq creation",
			dongles[i].queue);
		custom_assert("handle access mutex initialization",
			dongles[i].access_mutex_init == 1);
		custom_assert("handle access cond initialization",
			dongles[i].access_cond_init == 1);
		i++;
	}
}

int	main(void)
{
	t_dongle	*dongles;
	size_t		size;
	int			cooldown;

	size = 3;
	cooldown = 15;
	dongles = dongle_create(size, cooldown);
	test_group("test dongles creation");
	assert_is_not_null("handle valid array of dongles creation", dongles);
	_test_dongles(dongles, size, cooldown);
	dongle_destroy(&dongles, size);
	return (0);
}
