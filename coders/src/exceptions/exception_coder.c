/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_coder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:16:59 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:20 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for the coder module.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_coder(t_errcode errcode)
{
	if (errcode == ERR_CODER_MALLOC)
		fprintf(stderr, "exception: coder array malloc error\n");
	else if (errcode == ERR_CODER_ITEMS_MALLOC)
		fprintf(stderr, "exception: coder items malloc error\n");
	else if (errcode == ERR_CODER_MUTEX_INIT)
		fprintf(stderr, "exception: coder mutex init failed\n");
	else if (errcode == ERR_CODER_COND_INIT)
		fprintf(stderr, "exception: coder condition init failed\n");
	else
		fprintf(stderr, "exception: unknown coder error code %d\n", errcode);
}
