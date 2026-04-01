/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_thread_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:12:33 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 13:00:53 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"
#include <pthread.h>

void	workspace_thread_start(t_workspace *workspace)
{
	size_t	i;

	pthread_create(&workspace->thread_monitor_id, NULL, &workspace_monitor,
		workspace);
	i = 0;
	while (i < workspace->coders->count)
	{
		pthread_create(&workspace->coders->items[i].tid, NULL, &coder_routine,
			&workspace->coders->items[i]);
		i++;
	}
	pthread_mutex_lock(&workspace->coders->start_mutex);
	workspace->coders->can_start = 1;
	pthread_mutex_unlock(&workspace->coders->start_mutex);
	pthread_cond_broadcast(&workspace->coders->start_cond);
}
