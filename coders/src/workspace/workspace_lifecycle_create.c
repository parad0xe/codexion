/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_create.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:05:34 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:34:58 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "workspace.h"
#include <stdlib.h>
#include <string.h>

static t_errcode	_workspace_init(t_workspace *ws, t_args *args)
{
	ws->dongles = dongle_create(args->number_of_coders, args->dongle_cooldown);
	if (ws->dongles == NULL)
		return (ERR_DONGLE_MALLOC);
	ws->coders = coder_create(args, ws->dongles);
	if (ws->coders == NULL)
		return (ERR_CODER_MALLOC);
	return (0);
}

t_workspace	*workspace_create(t_args *args)
{
	t_workspace	*workspace;
	t_errcode	errcode;

	if (args == NULL)
		return (NULL);
	workspace = malloc(sizeof(t_workspace));
	if (workspace == NULL)
		return (NULL);
	memset(workspace, 0, sizeof(t_workspace));
	errcode = _workspace_init(workspace, args);
	if (errcode != 0)
	{
		workspace_destroy(&workspace);
		return (NULL);
	}
	return (workspace);
}
