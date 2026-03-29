/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:12:33 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 01:13:39 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"

void	workspace_start(t_workspace *workspace)
{
	size_t	i;

	pthread_mutex_lock(&workspace->start_mutex);
	i = 0;
	while (i < workspace->coder_count)
	{
		pthread_create(&workspace->coders[i].tid, NULL, &coder_routine,
			&workspace->coders[i]);
		i++;
	}
	pthread_mutex_unlock(&workspace->start_mutex);
}
