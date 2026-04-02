/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_heapq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:17:26 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:34 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for the heapq utility.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_heapq(t_errcode errcode)
{
	if (errcode == ERR_HEAPQ_MALLOC)
		fprintf(stderr, "exception: heapq malloc error\n");
	else if (errcode == ERR_HEAPQ_NULL)
		fprintf(stderr, "exception: heapq target is null\n");
	else
		fprintf(stderr, "exception: unknown heapq error code %d\n", errcode);
}
