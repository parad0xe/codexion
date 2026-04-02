/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_lifecycle_create.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:35:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:03:24 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "dongle.h"
#include "test.h"
#include <stddef.h>
#include <stdio.h>

static void	_init_mock_sim(t_sim_info *sim)
{
	sim->args.number_of_coders = 3;
	sim->args.time_to_burnout = 100;
	sim->args.time_to_compile = 200;
	sim->args.time_to_debug = 300;
	sim->args.time_to_refactor = 400;
	sim->args.number_of_compiles = 5;
	sim->args.dongle_cooldown = 15;
	sim->args.scheduler = "fifo";
}

static void	_test_dongles(t_dongle *dongles, t_sim_info *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->args.number_of_coders)
	{
		test_loop_group("test dongle", i);
		custom_assert("handle correct cooldown initialization",
			dongles[i].cooldown == sim->args.dongle_cooldown);
		custom_assert("handle availability initialization to 1",
			dongles[i].is_available == 1);
		assert_is_not_null("handle valid heapq creation", dongles[i].queue);
		custom_assert("handle access mutex initialization",
			dongles[i].access_mutex_init == 1);
		custom_assert("handle access cond initialization",
			dongles[i].access_cond_init == 1);
		i++;
	}
}

int	main(void)
{
	t_sim_info	sim;
	t_dongle	*dongles;

	_init_mock_sim(&sim);
	dongles = dongle_create(&sim);
	test_group("test dongles creation");
	assert_is_not_null("handle valid array of dongles creation", dongles);
	_test_dongles(dongles, &sim);
	dongle_destroy(&dongles, sim.args.number_of_coders);
	return (0);
}
