/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:03:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:27:56 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "workspace.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	debug_args(t_args args)
{
	printf("---- debug args ----\n");
	printf("number_of_coders   : %d\n", args.number_of_coders);
	printf("time_to_burnout    : %d\n", args.time_to_burnout);
	printf("time_to_compile    : %d\n", args.time_to_compile);
	printf("time_to_debug      : %d\n", args.time_to_debug);
	printf("time_to_refactor   : %d\n", args.time_to_refactor);
	printf("number_of_compiles : %d\n", args.number_of_compiles);
	printf("dongle_cooldown    : %d\n", args.dongle_cooldown);
	printf("scheduler          : %s\n", args.scheduler);
	printf("--------------------\n");
}

int	parse_args(t_args *args)
{
	args->number_of_coders = 4;
	args->time_to_burnout = 4000;
	args->time_to_compile = 400;
	args->time_to_debug = 400;
	args->time_to_refactor = 400;
	args->number_of_compiles = 3;
	args->dongle_cooldown = 60;
	args->scheduler = "fifo";
	return (0);
}

int	stop(t_workspace *workspace, int errcode)
{
	char	*message;
	size_t	l;

	if (errcode != 0)
	{
		message = "Error\n";
		write(2, message, strlen(message));
	}
	workspace_destroy(&workspace);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_workspace	*workspace;

	parse_args(&args);
	workspace = workspace_create(&args);
	if (workspace == NULL)
		return (stop(workspace, ERR_WORKSPACE_MALLOC));
	printf("normally terminated\n");
	return (stop(workspace, 0));
}
