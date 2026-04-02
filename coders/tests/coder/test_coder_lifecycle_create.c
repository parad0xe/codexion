/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:03:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:01:26 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "test.h"
#include <stddef.h>
#include <string.h>
#include <time.h>

static void	_init_mock_sim(t_sim_info *sim)
{
	sim->args.number_of_coders = 2;
	sim->args.time_to_burnout = 100;
	sim->args.time_to_compile = 200;
	sim->args.time_to_debug = 300;
	sim->args.time_to_refactor = 400;
	sim->args.number_of_compiles = 5;
	sim->args.dongle_cooldown = 10;
	sim->args.scheduler = "fifo";
}

static void	_test_coder_content(t_coder_array *coders, t_dongle *dongles,
		t_args *args)
{
	size_t	i;

	i = 0;
	while (i < coders->count)
	{
		test_loop_group("test coder", i);
		custom_assert("handle can_start flag init",
			*coders->items[i].can_start == 0);
		custom_assert("handle left dongle assignment",
			coders->items[i].left_dongle == &dongles[i]);
		custom_assert("handle right dongle assignment",
			coders->items[i].right_dongle == &dongles[(i + 1)
			% args->number_of_coders]);
		custom_assert("handle start mutex linking",
			coders->items[i].start_mutex == &coders->start_mutex);
		custom_assert("handle running mutex init",
			coders->items[i].is_running_mutex_init == 1);
		i++;
	}
}

static void	_test_single_coder(void)
{
	t_sim_info		sim;
	t_dongle		*dongles;
	t_coder_array	*coders;

	test_group("test single coder creation");
	_init_mock_sim(&sim);
	sim.args.number_of_coders = 1;
	dongles = dongle_create(&sim);
	assert_is_not_null("handle test dongles creation", dongles);
	coders = coder_create(&sim, dongles);
	assert_is_null("handle right dongle when alone (null)",
		coders->items[0].right_dongle);
	coder_destroy(&coders);
	dongle_destroy(&dongles, 1);
}

static void	_test_multiple_coder(void)
{
	t_sim_info		sim;
	t_dongle		*dongles;
	t_coder_array	*coders;
	struct timespec	ts;

	test_group("test multiple coder creation");
	_init_mock_sim(&sim);
	dongles = dongle_create(&sim);
	assert_is_not_null("handle test dongles creation", dongles);
	coders = coder_create(&sim, dongles);
	assert_is_not_null("handle coders array creation", coders);
	custom_assert("handle start mutex init", coders->start_mutex_init == 1);
	custom_assert("handle start cond init", coders->start_cond_init == 1);
	custom_assert("handle expected coder count",
		coders->count == sim.args.number_of_coders);
	_test_coder_content(coders, dongles, &sim.args);
	dongle_destroy(&dongles, coders->count);
	coder_destroy(&coders);
}

int	main(void)
{
	t_sim_info	sim;
	t_dongle	dongles;

	_test_single_coder();
	_test_multiple_coder();
	test_group("test null parameters");
	assert_is_null("handle null args pointer", coder_create(NULL, &dongles));
	assert_is_null("handle null dongles pointer", coder_create(&sim, NULL));
	assert_is_null("handle both null pointers", coder_create(NULL, NULL));
	return (0);
}
