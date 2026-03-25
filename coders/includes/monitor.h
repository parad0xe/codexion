/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:51:02 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 14:05:02 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "coders.h"
# include "codexion.h"
# include <pthread.h>

typedef struct s_monitor
{
	pthread_t	tid;
	t_args		*args;
	t_coders	*coders;
}				t_monitor;

int				monitor_init(t_monitor *monitor, t_coders *coders,
					t_args *args);
void			*monitor_routine(void *thread_args);
int				monitor_thread_start(t_monitor *monitor);
int				monitor_thread_join(t_monitor *monitor);
void			debug_monitor(t_monitor *monitor);

#endif
