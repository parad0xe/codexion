/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:56:26 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 18:21:20 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Prints the parsed arguments to standard output for debugging.
 *
 * @param args Structure containing the parsed simulation arguments
 */
void	args_debug(t_args args)
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

/**
 * @brief Checks if a string contains only numeric digits.
 *
 * @param str Target string to evaluate
 * @return 1 if valid, 0 otherwise
 */
static int	_is_valid_uint_str(char *str)
{
	unsigned int	i;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Parses a string into an unsigned integer with error tracking.
 *
 * @param str Target string to parse
 * @param out Pointer to store the parsed value
 * @param errcode Pointer to the tracked error state
 */
void	_parse_uint(char *str, unsigned int *out, t_errcode *errcode)
{
	if (*errcode != 0)
		return ;
	if (!_is_valid_uint_str(str))
		*errcode = ERR_ARG_INVALID_UINT;
	if (*errcode == 0)
		*out = atoi(str);
}

/**
 * @brief Parses command line arguments into the simulation structure.
 *
 * @param sim Global simulation information and configuration
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return 1 on success, 0 on failure
 */
int	args_parse(t_sim_info *sim, int argc, char **argv)
{
	if (argc != 9)
	{
		sim->errcode = ERR_ARGS_MISMATCH;
		return (0);
	}
	_parse_uint(argv[1], &sim->args.number_of_coders, &sim->errcode);
	_parse_uint(argv[2], &sim->args.time_to_burnout, &sim->errcode);
	_parse_uint(argv[3], &sim->args.time_to_compile, &sim->errcode);
	_parse_uint(argv[4], &sim->args.time_to_debug, &sim->errcode);
	_parse_uint(argv[5], &sim->args.time_to_refactor, &sim->errcode);
	_parse_uint(argv[6], &sim->args.number_of_compiles, &sim->errcode);
	_parse_uint(argv[7], &sim->args.dongle_cooldown, &sim->errcode);
	if (sim->errcode != 0)
		return (0);
	sim->args.scheduler = argv[8];
	if (strcmp(sim->args.scheduler, "fifo") != 0 && strcmp(sim->args.scheduler,
			"edf") != 0)
	{
		sim->errcode = ERR_ARG_SCHEDULER;
		return (0);
	}
	return (1);
}
