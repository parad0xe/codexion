/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_monitor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:20:37 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:19:36 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "workspace.h"
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
 * @brief Checks if any coder burned out or if all reached the compile goal.
 *
 * @param ws Workspace containing the coders to evaluate
 * @return 1 if simulation should stop, 0 otherwise
 */
static int	_check_coders_state(t_workspace *ws)
{
	unsigned int	i;
	unsigned int	completed;
	t_coder			*coder;

	i = 0;
	completed = 0;
	while (i < ws->coders->count)
	{
		coder = &ws->coders->items[i];
		if (coder_has_burnout_thread_safe(coder))
		{
			_stop_coders(ws);
			coder_log_thread_safe(coder, "burn out", LOG_ALWAYS);
			return (1);
		}
		if (coder_reached_compilation_count_thread_safe(coder))
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
 * @brief Evaluates the global simulation state for any critical errors.
 *
 * @param ws Workspace containing the simulation error state
 * @return 1 if simulation should stop, 0 otherwise
 */
static int	_check_sim_state(t_workspace *ws)
{
	if (ws->sim->errcode != 0)
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
		if (_check_coders_state(ws))
			break ;
		if (_check_sim_state(ws))
			break ;
		usleep(500);
	}
	return (NULL);
}
