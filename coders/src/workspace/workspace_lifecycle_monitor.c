/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_monitor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:20:37 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:27:59 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include "workspace.h"
#include <stdio.h>

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
		time_sleep_ms(1);
	}
	return (NULL);
}
