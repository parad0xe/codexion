/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:03:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 21:57:07 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "exception.h"
#include "utils.h"
#include "workspace.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int	simulation_init(t_sim_info *sim, int argc, char **argv)
{
	memset(sim, 0, sizeof(t_sim_info));
	if (!args_parse(sim, argc, argv))
		return (0);
	if (pthread_mutex_init(&sim->log_mutex, NULL) != 0)
	{
		sim->errcode = ERR_SIM_MUTEX_INIT;
		return (0);
	}
	sim->log_mutex_init = 1;
	time_set_abstimeout(&sim->started_at, 0);
	return (1);
}

t_errcode	stop(t_sim_info *sim, t_workspace *workspace)
{
	if (sim->log_mutex_init)
		pthread_mutex_destroy(&sim->log_mutex);
	workspace_destroy(&workspace);
	if (sim->errcode != 0)
		exception(sim->errcode);
	return (sim->errcode);
}

int	main(int argc, char **argv)
{
	t_sim_info	sim;
	t_workspace	*workspace;

	if (!simulation_init(&sim, argc, argv))
		return (stop(&sim, NULL));
	if (sim.args.number_of_compiles == 0)
		return (stop(&sim, NULL));
	workspace = workspace_create(&sim);
	if (workspace == NULL)
		return (stop(&sim, workspace));
	workspace_thread_start(workspace);
	workspace_thread_join(workspace);
	return (stop(&sim, workspace));
}
