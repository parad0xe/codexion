/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:03:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:46:35 by nlallema         ###   ########lyon.fr   */
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

int	main(void)
{
	t_args			args;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_mutex_t	start_mutex;

	_init_mock_args(&args);
	pthread_mutex_init(&start_mutex, NULL);
	dongles = dongle_create(args.number_of_coders, args.dongle_cooldown);
	custom_assert("create valid dongles for testing", dongles != NULL);
	coders = coder_create(&args, dongles, &start_mutex);
	custom_assert("create valid coders array", coders != NULL);
	custom_assert("assign left dongle", coders[0].left_dongle == &dongles[0]);
	custom_assert("assign right dongle", coders[0].right_dongle == &dongles[1]);
	custom_assert("assign start mutex", coders[0].start_mutex == &start_mutex);
	custom_assert("set correct scheduler", strcmp(coders[0].scheduler,
			"fifo") == 0);
	coder_destroy(&coders);
	custom_assert("return NULL if args is NULL", coder_create(NULL, dongles,
			&start_mutex) == NULL);
	custom_assert("return NULL if dongles is NULL", coder_create(&args, NULL,
			&start_mutex) == NULL);
	dongle_destroy(&dongles, args.number_of_coders);
	pthread_mutex_destroy(&start_mutex);
	return (0);
}
