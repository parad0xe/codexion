/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_monitor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:20:37 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:32:14 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include "workspace.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Safely updates the running state of all coders to false.
 *
 * @param ws Workspace containing the coders to stop
 */
void	_stop_coders(t_workspace *ws)
{
	unsigned int	i;
	t_coder			*coder;

	i = 0;
	while (i < ws->coders->count)
	{
		coder = &ws->coders->items[i];
		coder_set_running_thread_safe(coder, 0);
		i++;
	}
}

/**
 * @brief Checks for any burnout and stops all coders if one occurred.
 *
 * @param ws Workspace containing the coders to evaluate
 * @return 1 if a burnout was detected, 0 otherwise
 */
static int	_stop_on_any_burnout(t_workspace *ws)
{
	unsigned int	i;
	t_coder			*coder;

	i = 0;
	while (i < ws->coders->count)
	{
		coder = &ws->coders->items[i];
		if (coder_has_burnout(coder))
		{
			_stop_coders(ws);
			coder_log_thread_safe(coder, "burn out", LOG_ALWAYS);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Stops the simulation if all coders reached the compile goal.
 *
 * @param ws Workspace containing the coders to evaluate
 * @return 1 if all coders have finished, 0 otherwise
 */
static int	_stop_on_all_finished(t_workspace *ws)
{
	unsigned int	i;
	unsigned int	completed;
	t_coder			*coder;

	i = 0;
	completed = 0;
	while (i < ws->coders->count)
	{
		coder = &ws->coders->items[i];
		if (coder->compilation_count >= ws->sim->args.number_of_compiles)
			completed++;
		i++;
	}
	if (completed == ws->coders->count)
	{
		_stop_coders(ws);
		return (1);
	}
	return (0);
}

/**
 * @brief Main monitoring loop checking for burnouts or completion.
 *
 * @param thread_arg Generic pointer to the workspace structure
 * @return NULL upon completion
 */
void	*workspace_monitor(void *thread_arg)
{
	t_workspace	*ws;

	ws = (t_workspace *)thread_arg;
	while (1)
	{
		if (_stop_on_any_burnout(ws))
			break ;
		if (_stop_on_all_finished(ws))
			break ;
		usleep(500);
	}
	return (NULL);
}
