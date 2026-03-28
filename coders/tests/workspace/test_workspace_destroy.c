/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_workspace_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:16:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:18:52 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "workspace.h"
#include <stddef.h>

static void	_init_mock_args(t_args *args)
{
	args->number_of_coders = 2;
	args->time_to_burnout = 100;
	args->time_to_compile = 200;
	args->time_to_debug = 300;
	args->time_to_refactor = 400;
	args->number_of_compiles = 5;
	args->dongle_cooldown = 10;
}

int	main(void)
{
	t_args		args;
	t_workspace	*workspace;

	_init_mock_args(&args);
	workspace = workspace_create(&args);
	custom_assert("allocate workspace properly", workspace != NULL);
	workspace_destroy(&workspace);
	custom_assert("set pointer to NULL after destroy", workspace == NULL);
	workspace_destroy(&workspace);
	custom_assert("safely handle already NULL pointer", workspace == NULL);
	return (0);
}
