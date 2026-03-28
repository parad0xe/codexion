/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_workspace_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:15:42 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:18:37 by nlallema         ###   ########lyon.fr   */
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
}

int	main(void)
{
	t_args		args;
	t_workspace	*workspace;

	_init_mock_args(&args);
	workspace = workspace_create(&args);
	custom_assert("create valid workspace", workspace != NULL);
	custom_assert("set correct coder count", workspace->coder_count == 3);
	custom_assert("create valid manager pool", workspace->manager_pool != NULL);
	custom_assert("create valid coders array", workspace->coders != NULL);
	workspace_destroy(&workspace);
	return (0);
}
