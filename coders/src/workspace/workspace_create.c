/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:05:34 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:12:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "dongle.h"
#include "workspace.h"
#include <stdlib.h>
#include <string.h>

t_workspace	*workspace_create(t_args *args)
{
	t_workspace	*workspace;

	workspace = malloc(sizeof(t_workspace));
	if (workspace == NULL)
		return (NULL);
	memset(workspace, 0, sizeof(t_workspace));
	workspace->coder_count = args->number_of_coders;
	workspace->manager_pool = dmp_create(args->number_of_coders,
			args->dongle_cooldown);
	if (workspace->manager_pool == NULL)
	{
		workspace_destroy(&workspace);
		return (NULL);
	}
	workspace->coders = coders_create(args, workspace->manager_pool);
	if (workspace->coders == NULL)
	{
		workspace_destroy(&workspace);
		return (NULL);
	}
	return (workspace);
}
