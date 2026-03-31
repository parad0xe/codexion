/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:03:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:42:25 by nlallema         ###   ########lyon.fr   */
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

static void	_run_tests(t_coder_array *coders, t_dongle *dongles, t_args *args)
{
	custom_assert("create valid mutex", coders->start_mutex_init == 1);
	custom_assert("create expected count",
		coders->count == args->number_of_coders);
	custom_assert("coders cannot start", *coders->items[0].can_start == 0);
	custom_assert("assign left dongle",
		coders->items[0].left_dongle == &dongles[0]);
	custom_assert("assign right dongle",
		coders->items[0].right_dongle == &dongles[1]);
	custom_assert("assign start mutex",
		coders->items[0].start_mutex == &coders->start_mutex);
	custom_assert("set correct scheduler", strcmp(coders->items[0].scheduler,
			"fifo") == 0);
}

int	main(void)
{
	t_args			args;
	t_dongle		*dongles;
	t_coder_array	*coders;

	_init_mock_args(&args);
	dongles = dongle_create(args.number_of_coders, args.dongle_cooldown);
	custom_assert("create valid dongles for testing", dongles != NULL);
	coders = coder_create(&args, dongles);
	custom_assert("create valid coders array", coders != NULL);
	_run_tests(coders, dongles, &args);
	dongle_destroy(&dongles, coders->count);
	coder_destroy(&coders);
	custom_assert("return NULL if args is NULL", coder_create(NULL,
			dongles) == NULL);
	custom_assert("return NULL if dongles is NULL", coder_create(&args,
			NULL) == NULL);
	return (0);
}
