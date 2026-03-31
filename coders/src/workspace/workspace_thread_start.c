/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_thread_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:12:33 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:43:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"
#include <pthread.h>

void	workspace_thread_start(t_workspace *workspace)
{
	size_t	i;

	i = 0;
	while (i < workspace->coders->count)
	{
		pthread_create(&workspace->coders->items[i].tid, NULL, &coder_routine,
			&workspace->coders->items[i]);
		i++;
	}
	workspace->coders->can_start = 1;
	pthread_cond_broadcast(&workspace->coders->start_cond);
}
