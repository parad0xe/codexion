/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:16:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 21:57:54 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages for command line arguments parsing.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_args(t_errcode errcode)
{
	if (errcode == ERR_ARGS_MISMATCH)
		fprintf(stderr, "exception: invalid number of arguments\n");
	else if (errcode == ERR_ARG_INVALID_UINT)
		fprintf(stderr, "exception: arguments must be positive integers\n");
	else if (errcode == ERR_ARG_SCHEDULER)
		fprintf(stderr, "exception: scheduler must be 'fifo' or 'edf'\n");
	else
		fprintf(stderr, "exception: unknown args error code %d\n", errcode);
}
