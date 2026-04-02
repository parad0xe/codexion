/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:03:21 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:01:39 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "utils.h"
#include "workspace.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>

t_errcode	simulation_init(t_sim_info *sim, int argc, char **argv)
{
	t_errcode	errcode;

	args_parse(&sim->args, argc, argv);
	errcode = pthread_mutex_init(&sim->log_mutex, NULL);
	if (errcode != 0)
		return (ERR_MUTEX_INIT);
	sim->log_mutex_init = 1;
	time_set_abstimeout(&sim->started_at, 0);
	return (0);
}

t_errcode	stop(t_sim_info *sim, t_workspace *workspace, int errcode)
{
	char	*message;

	if (errcode != 0)
	{
		message = "Error\n";
		write(2, message, strlen(message));
	}
	if (sim->log_mutex_init)
		pthread_mutex_destroy(&sim->log_mutex);
	workspace_destroy(&workspace);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_sim_info	sim;
	t_workspace	*workspace;
	t_errcode	errcode;

	errcode = simulation_init(&sim, argc, argv);
	if (errcode != 0)
		return (errcode);
	if (sim.args.number_of_compiles == 0)
		return (stop(&sim, NULL, 0));
	workspace = workspace_create(&sim);
	if (workspace == NULL)
		return (stop(&sim, workspace, ERR_WORKSPACE_MALLOC));
	workspace_thread_start(workspace);
	workspace_thread_join(workspace);
	return (stop(&sim, workspace, 0));
}
