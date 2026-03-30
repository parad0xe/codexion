/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_lifecycle_create.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:35:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 16:52:51 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"
#include <stddef.h>
#include <stdio.h>

static void	_test_dongles(t_dongle *dongles, size_t size, int cooldown)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		print_test_loop_name("test dongle", i);
		custom_assert("create valid array of dongles", dongles != NULL);
		custom_assert("initialize correct cooldown",
			dongles[i].cooldown == cooldown);
		custom_assert("set availability to 1", dongles[i].is_available == 1);
		custom_assert("create valid heapq", dongles[i].queue != NULL);
		custom_assert("init access mutex", dongles[i].access_mutex_init == 1);
		custom_assert("init access cond", dongles[i].access_cond_init == 1);
		i++;
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
	dongles = dongle_create(size, cooldown);
	_test_dongles(dongles, size, cooldown);
	dongle_destroy(&dongles, size);
	return (0);
}
