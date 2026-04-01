/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_monitor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:20:37 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 17:02:20 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include "workspace.h"
#include <stdio.h>

void	*workspace_monitor(void *thread_arg)
{
	t_workspace		*ws;
	t_coder			*coder;
	unsigned int	i;
	unsigned int	completed_tasks;
	int				has_burnout;

	ws = (t_workspace *)thread_arg;
	completed_tasks = 0;
	has_burnout = 0;
	printf("monitor started\n");
	while (completed_tasks != ws->coders->count && !has_burnout)
	{
		i = 0;
		completed_tasks = 0;
		while (i < ws->coders->count)
		{
			coder = &ws->coders->items[i];
			if (coder_has_burnout(coder))
			{
				printf("CODER %d has burnout\n", coder->id);
				i = 0;
				while (i < ws->coders->count)
				{
					coder = &ws->coders->items[i];
					coder_set_running_thread_safe(coder, 0);
					i++;
				}
				has_burnout = 1;
				break ;
			}
			if (coder->number_of_compiles >= ws->required_compilation_count)
				completed_tasks += 1;
			i++;
		}
		time_sleep_ms(1);
	}
	i = 0;
	while (i < ws->coders->count)
	{
		coder = &ws->coders->items[i];
		coder_set_running_thread_safe(coder, 0);
		i++;
	}
	printf("monitor exit. all coder has finished.\n");
	return (NULL);
}
