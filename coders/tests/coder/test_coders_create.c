/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coders_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:03:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:25:53 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "dongle.h"
#include "test.h"
#include <stddef.h>

static void	_init_mock_args(t_args *args)
{
	args->number_of_coders = 2;
	args->time_to_burnout = 100;
	args->time_to_compile = 200;
	args->time_to_debug = 300;
	args->time_to_refactor = 400;
	args->number_of_compiles = 5;
}

static void	_run_test(t_args *args, t_coder *coders,
		t_dongle_manager_pool *pool)
{
	custom_assert("create valid pool for testing", pool != NULL);
	coders = coders_create(args, pool);
	custom_assert("create valid coders array", coders != NULL);
	custom_assert("assign correct manager [0]",
		coders[0].dongle_manager == &pool->managers[0]);
	custom_assert("assign correct manager [1]",
		coders[1].dongle_manager == &pool->managers[1]);
	custom_assert("set correct burnout time", coders[0].time_to_burnout == 100);
	coders_destroy(&coders);
	custom_assert("return NULL if args is NULL", coders_create(NULL,
			pool) == NULL);
	custom_assert("return NULL if pool is NULL", coders_create(args,
			NULL) == NULL);
	pool->count = 3;
	custom_assert("return NULL if count mismatch", coders_create(args,
			pool) == NULL);
	pool->count = 2;
}

int	main(void)
{
	t_args					args;
	t_dongle_manager_pool	*pool;
	t_coder					*coders;

	_init_mock_args(&args);
	pool = dmp_create(args.number_of_coders, args.dongle_cooldown);
	_run_test(&args, coders, pool);
	dmp_destroy(&pool);
	return (0);
}
