/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:03:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:13:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"
#include "test.h"
#include <stddef.h>
#include <string.h>

static void	_init_mock_args(t_args *args)
{
	args->number_of_coders = 2;
	args->time_to_burnout = 100;
	args->time_to_compile = 200;
	args->time_to_debug = 300;
	args->time_to_refactor = 400;
	args->number_of_compiles = 5;
	args->dongle_cooldown = 10;
	args->scheduler = "fifo";
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
		custom_assert("handle scheduler policy setting",
			strcmp(coders->items[i].scheduler, "fifo") == 0);
		i++;
	}
}

static void	_test_single_coder(void)
{
	t_args			args;
	t_dongle		*dongles;
	t_coder_array	*coders;

	test_group("test single coder creation");
	_init_mock_args(&args);
	args.number_of_coders = 1;
	dongles = dongle_create(1, args.dongle_cooldown);
	assert_is_not_null("handle test dongles creation", dongles);
	coders = coder_create(&args, dongles);
	assert_is_null("handle right dongle when alone (null)",
		coders->items[0].right_dongle);
	dongle_destroy(&dongles, 1);
	coder_destroy(&coders);
}

static void	_test_multiple_coder(void)
{
	t_args			args;
	t_dongle		*dongles;
	t_coder_array	*coders;

	test_group("test multiple coder creation");
	_init_mock_args(&args);
	dongles = dongle_create(args.number_of_coders, args.dongle_cooldown);
	assert_is_not_null("handle test dongles creation", dongles);
	coders = coder_create(&args, dongles);
	assert_is_not_null("handle coders array creation", coders);
	custom_assert("handle start mutex init", coders->start_mutex_init == 1);
	custom_assert("handle start cond init", coders->start_cond_init == 1);
	custom_assert("handle expected coder count",
		coders->count == args.number_of_coders);
	_test_coder_content(coders, dongles, &args);
	dongle_destroy(&dongles, coders->count);
	coder_destroy(&coders);
}

int	main(void)
{
	t_args		args;
	t_dongle	dongles;

	_test_single_coder();
	_test_multiple_coder();
	test_group("test null parameters");
	assert_is_null("handle null args pointer", coder_create(NULL, &dongles));
	assert_is_null("handle null dongles pointer", coder_create(&args, NULL));
	assert_is_null("handle both null pointers", coder_create(NULL, NULL));
	return (0);
}
