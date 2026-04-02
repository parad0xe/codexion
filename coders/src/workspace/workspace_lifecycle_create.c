/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:05:34 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:28:27 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "workspace.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initializes the workspace and allocates its internal arrays.
 *
 * @param ws Target workspace structure to initialize
 * @param sim Global simulation information and configuration
 * @return 0 on success, error code otherwise
 */
static t_errcode	_workspace_init(t_workspace *ws, t_sim_info *sim)
{
	ws->sim = sim;
	ws->dongles = dongle_create(sim->args.number_of_coders,
			sim->args.dongle_cooldown);
	if (ws->dongles == NULL)
		return (ERR_DONGLE_MALLOC);
	ws->coders = coder_create(ws->sim, ws->dongles);
	if (ws->coders == NULL)
		return (ERR_CODER_MALLOC);
	return (0);
}

/**
 * @brief Allocates and initializes the complete simulation workspace.
 *
 * @param sim Global simulation information and configuration
 * @return Pointer to the allocated workspace, or NULL on failure
 */
t_workspace	*workspace_create(t_sim_info *sim)
{
	t_workspace	*workspace;
	t_errcode	errcode;

	if (sim == NULL)
		return (NULL);
	workspace = malloc(sizeof(t_workspace));
	if (workspace == NULL)
		return (NULL);
	memset(workspace, 0, sizeof(t_workspace));
	errcode = _workspace_init(workspace, sim);
	if (errcode != 0)
	{
		workspace_destroy(&workspace);
		return (NULL);
	}
	return (workspace);
}
