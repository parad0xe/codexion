/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_thread_join.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:14:20 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:30:15 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"

/**
 * @brief Waits for all coder threads and the monitor to terminate.
 *
 * @param workspace Target workspace containing the running threads
 */
void	workspace_thread_join(t_workspace *workspace)
{
	size_t	i;

	i = 0;
	while (i < workspace->coders->count)
	{
		pthread_join(workspace->coders->items[i].tid, NULL);
		i++;
	}
	pthread_join(workspace->thread_monitor_id, NULL);
}
