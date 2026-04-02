/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_sys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:15:59 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for system threads.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_sys(t_errcode errcode)
{
	if (errcode == ERR_THREAD_CREATE)
		fprintf(stderr, "exception: thread creation failed\n");
	else if (errcode == ERR_THREAD_JOIN)
		fprintf(stderr, "exception: thread join failed\n");
	else
		fprintf(stderr, "exception: unknown sys error code %d\n", errcode);
}
