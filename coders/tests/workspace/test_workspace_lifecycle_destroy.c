/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_workspace_lifecycle_destroy.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:16:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:25:24 by nlallema         ###   ########lyon.fr   */
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
	args->scheduler = "fifo";
}

static void	_test_workspace_destroy(void)
{
	t_args		args;
	t_workspace	*workspace;

	test_group("test workspace destroy");
	_init_mock_args(&args);
	workspace = workspace_create(&args);
	assert_is_not_null("handle workspace allocation properly", workspace);
	workspace_destroy(&workspace);
	assert_is_null("handle pointer reset to null after destroy", workspace);
	workspace_destroy(&workspace);
	assert_is_null("handle already null pointer safely", workspace);
}

int	main(void)
{
	_test_workspace_destroy();
	return (0);
}
