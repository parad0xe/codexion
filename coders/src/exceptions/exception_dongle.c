/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_dongle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:16:35 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:29 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for the dongle module.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_dongle(t_errcode errcode)
{
	if (errcode == ERR_DONGLE_MALLOC)
		fprintf(stderr, "exception: dongle array malloc error\n");
	else if (errcode == ERR_DONGLE_MUTEX_INIT)
		fprintf(stderr, "exception: dongle mutex init failed\n");
	else if (errcode == ERR_DONGLE_COND_INIT)
		fprintf(stderr, "exception: dongle condition init failed\n");
	else
		fprintf(stderr, "exception: unknown dongle error code %d\n", errcode);
}
