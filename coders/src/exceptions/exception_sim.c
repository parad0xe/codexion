/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_sim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:17:17 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:39 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for the global simulation state.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_sim(t_errcode errcode)
{
	if (errcode == ERR_SIM_MUTEX_INIT)
		fprintf(stderr, "exception: sim mutex init failed\n");
	else
		fprintf(stderr, "exception: unknown sim error code %d\n", errcode);
}
