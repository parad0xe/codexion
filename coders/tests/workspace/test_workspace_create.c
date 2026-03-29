/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_workspace_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:42 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 22:28:14 by nlallema         ###   ########lyon.fr   */
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

int	main(void)
{
	t_args		args;
	t_workspace	*ws;

	_init_mock_args(&args);
	ws = workspace_create(&args);
	custom_assert("create valid workspace", ws != NULL);
	custom_assert("set correct coder count", ws->coder_count == 3);
	custom_assert("init start mutex", ws->start_mutex_init == 1);
	custom_assert("create valid dongles array", ws->dongles != NULL);
	custom_assert("create valid coders array", ws->coders != NULL);
	workspace_destroy(&ws);
	return (0);
}
