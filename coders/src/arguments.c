/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:56:26 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:15:20 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

void	args_debug(t_args args)
{
	printf("---- debug args ----\n");
	printf("number_of_coders   : %ld\n", args.number_of_coders);
	printf("time_to_burnout    : %ld\n", args.time_to_burnout);
	printf("time_to_compile    : %ld\n", args.time_to_compile);
	printf("time_to_debug      : %ld\n", args.time_to_debug);
	printf("time_to_refactor   : %ld\n", args.time_to_refactor);
	printf("number_of_compiles : %ld\n", args.number_of_compiles);
	printf("dongle_cooldown    : %ld\n", args.dongle_cooldown);
	printf("scheduler          : %s\n", args.scheduler);
	printf("--------------------\n");
}

int	args_parse(t_args *args, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	args->number_of_coders = 5;
	args->time_to_burnout = 184;
	args->time_to_compile = 50;
	args->time_to_debug = 30;
	args->time_to_refactor = 20;
	args->number_of_compiles = 2;
	args->dongle_cooldown = 10;
	args->scheduler = "fifo";
	return (0);
}
