/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_workspace_lifecycle_create.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:42 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:24:04 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "workspace.h"
#include <stddef.h>

static void	_init_mock_args(t_args *args)
{
	args->number_of_coders = 3;
	args->time_to_burnout = 100;
	args->time_to_compile = 200;
	args->time_to_debug = 300;
	args->time_to_refactor = 400;
	args->number_of_compiles = 5;
	args->dongle_cooldown = 15;
	args->scheduler = "edf";
}

static void	_test_workspace_create(void)
{
	t_args		args;
	t_workspace	*ws;

	test_group("test workspace create");
	_init_mock_args(&args);
	ws = workspace_create(&args);
	assert_is_not_null("handle valid workspace creation", ws);
	assert_is_not_null("handle valid dongles array creation", ws->dongles);
	assert_is_not_null("handle valid coders array creation", ws->coders);
	custom_assert("handle valid coders count",
		ws->coders->count == args.number_of_coders);
	workspace_destroy(&ws);
}

int	main(void)
{
	_test_workspace_create();
	test_group("test null parameters");
	assert_is_null("handle null args pointer", workspace_create(NULL));
	return (0);
}
