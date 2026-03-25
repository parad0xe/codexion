/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:03:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 22:05:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "codexion.h"
#include "heapq.h"
#include "monitor.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	args->time_to_burnout = 400;
	args->time_to_compile = 400;
	args->time_to_debug = 400;
	args->time_to_refactor = 400;
	args->number_of_compiles = 3;
	args->dongle_cooldown = 60;
	args->scheduler = "fifo";
	return (0);
}

int	stop(t_coders *coders, int errcode)
{
	char	*s;
	size_t	l;

	if (errcode != 0)
	{
		s = "Error\n";
		l = strlen(s);
		write(2, s, l);
	}
	coders_destroy(coders);
	return (errcode);
}

int	init(t_args *args, t_coders *coders, t_monitor *monitor)
{
	int	errcode;

	errcode = parse_args(args);
	if (errcode != 0)
		return (errcode);
	errcode = coders_init(coders, args);
	if (errcode != 0)
		return (errcode);
	return (monitor_init(monitor, coders, args));
}

int	main(int argc, char **argv)
{
	t_heapq	*heapq;

	// t_args		args;
	// int			errcode;
	// t_coders	coders;
	// t_monitor	monitor;
	// errcode = init(&args, &coders, &monitor);
	// if (errcode != 0)
	//	return (stop(&coders, errcode));
	// debug_args(args);
	// debug_monitor(&monitor);
	// debug_coders(&coders, &args);
	// errcode = coders_thread_start(&coders, &args);
	// if (errcode != 0)
	//	return (stop(&coders, errcode));
	// errcode = monitor_thread_start(&monitor);
	// if (errcode != 0)
	//	return (stop(&coders, errcode));
	// errcode = coders_thread_join(&coders, &args);
	// if (errcode != 0)
	//	return (stop(&coders, errcode));
	// errcode = monitor_thread_join(&monitor);
	// if (errcode != 0)
	//	return (stop(&coders, errcode));
	// printf("end\n");
	// return (stop(&coders, errcode));
}
