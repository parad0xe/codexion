/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_workspace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:17:09 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:47 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

/**
 * @brief Prints error messages strictly for the workspace module.
 *
 * @param errcode The specific error code to evaluate and print
 */
void	exception_workspace(t_errcode errcode)
{
	if (errcode == ERR_WORKSPACE_MALLOC)
		fprintf(stderr, "exception: workspace malloc error\n");
	else
		fprintf(stderr, "exception: unknown workspace error code %d\n",
			errcode);
}
