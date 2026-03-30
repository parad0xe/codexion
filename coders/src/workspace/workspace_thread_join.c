/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_thread_join.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:14:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 12:40:17 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"

void	workspace_thread_join(t_workspace *workspace)
{
	size_t	i;

	i = 0;
	while (i < workspace->coder_count)
	{
		pthread_join(workspace->coders[i].tid, NULL);
		i++;
	}
}
