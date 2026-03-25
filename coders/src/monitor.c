/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:39:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 14:39:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include "monitor.h"
#include <stdio.h>
#include <unistd.h>

int	monitor_init(t_monitor *monitor, t_coders *coders, t_args *args)
{
	monitor->tid = 0;
	monitor->args = args;
	monitor->coders = coders;
	return (0);
}

void	*monitor_routine(void *thread_args)
{
	t_monitor	*monitor;
	int			i;

	printf("Monitor started\n");
	monitor = (t_monitor *)thread_args;
	i = -1;
	while (++i < monitor->args->number_of_coders)
	{
		printf("Monitor: coder %lu\n", monitor->coders->coders[i].tid);
		usleep(300 * 1000);
	}
	return (NULL);
}

int	monitor_thread_start(t_monitor *monitor)
{
	int	errcode;

	errcode = pthread_create(&monitor->tid, NULL, &monitor_routine, monitor);
	if (errcode != 0)
		return (ERR_THREAD_CREATE);
	return (0);
}

int	monitor_thread_join(t_monitor *monitor)
{
	int	errcode;

	errcode = pthread_join(monitor->tid, NULL);
	if (errcode != 0)
		return (ERR_THREAD_JOIN);
	return (0);
}

void	debug_monitor(t_monitor *monitor)
{
	if (!monitor)
	{
		printf("--- Debug Monitor : NULL ---\n");
		return ;
	}
	printf("--- Debug Monitor ---\n");
	printf("tid        : %p\n", (void *)monitor->tid);
	if (monitor->args)
		printf("args       : %p (valid)\n", (void *)monitor->args);
	else
		printf("args       : (null)\n");
	if (monitor->coders)
		printf("coders     : %p (valid)\n", (void *)monitor->coders);
	else
		printf("coders     : (null)\n");
	printf("-----------------------\n");
}
