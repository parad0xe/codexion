/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:14:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 01:15:06 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"

void	workspace_join(t_workspace *workspace)
{
	size_t	i;

	i = 0;
	while (i < workspace->coder_count)
	{
		pthread_join(workspace->coders[i].tid, NULL);
		i++;
	}
}
