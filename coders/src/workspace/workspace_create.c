/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:05:34 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:44:55 by nlallema         ###   ########lyon.fr   */
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
	t_errcode	errcode;

	errcode = pthread_mutex_init(&ws->start_mutex, NULL);
	if (errcode != 0)
		return (ERR_MUTEX_INIT);
	ws->start_mutex_init = 1;
	ws->coder_count = args->number_of_coders;
	ws->dongles = dongle_create(args->number_of_coders, args->dongle_cooldown);
	if (ws->dongles == NULL)
		return (ERR_DONGLE_MALLOC);
	ws->coders = coder_create(args, ws->dongles, &ws->start_mutex);
	if (ws->coders == NULL)
		return (ERR_CODER_MALLOC);
	return (0);
}

t_workspace	*workspace_create(t_args *args)
{
	t_workspace	*workspace;
	t_errcode	errcode;

	workspace = malloc(sizeof(t_workspace));
	if (workspace == NULL)
		return (NULL);
	memset(workspace, 0, sizeof(t_workspace));
	errcode = _workspace_init(workspace, args);
	errcode = pthread_mutex_init(&workspace->start_mutex, NULL);
	if (errcode != 0)
	{
		workspace_destroy(&workspace);
		return (NULL);
	}
	return (workspace);
}
