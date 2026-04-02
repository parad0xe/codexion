/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_lifecycle_destroy.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:41:10 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:04:29 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

static void	_init_mock_sim(t_sim_info *sim)
{
	sim->args.number_of_coders = 5;
	sim->args.time_to_burnout = 100;
	sim->args.time_to_compile = 200;
	sim->args.time_to_debug = 300;
	sim->args.time_to_refactor = 400;
	sim->args.number_of_compiles = 5;
	sim->args.dongle_cooldown = 10;
	sim->args.scheduler = "fifo";
}

static void	_test_dongle_destroy(void)
{
	t_sim_info	sim;
	t_dongle	*dongles;
	size_t		size;

	_init_mock_sim(&sim);
	test_group("test dongles destroy");
	dongles = dongle_create(&sim);
	assert_is_not_null("handle valid array of dongles creation", dongles);
	dongle_destroy(&dongles, sim.args.number_of_coders);
	assert_is_null("handle pointer reset to null after destroy", dongles);
	dongle_destroy(&dongles, sim.args.number_of_coders);
	assert_is_null("handle already null pointer safely", dongles);
}

int	main(void)
{
	_test_dongle_destroy();
	return (0);
}
