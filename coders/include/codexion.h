/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:35:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:01:51 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stddef.h>
# include <time.h>

// project-side errors
# define ERR_MALLOC 1
# define ERR_THREAD_CREATE 2
# define ERR_THREAD_JOIN 3
# define ERR_MUTEX_INIT 4
# define ERR_COND_INIT 5

// heapq errors
# define ERR_HEAPQ_MALLOC 10
# define ERR_HEAPQ_NULL 11

// dongle errors
# define ERR_DONGLE_MALLOC 20
# define ERR_DONGLE_MANAGER_MALLOC 21

// coder errors
# define ERR_CODER_MALLOC 30

// workspace errors
# define ERR_WORKSPACE_MALLOC 40

typedef int			t_errcode;

typedef struct s_args
{
	size_t			number_of_coders;
	size_t			time_to_burnout;
	size_t			time_to_compile;
	size_t			time_to_debug;
	size_t			time_to_refactor;
	size_t			number_of_compiles;
	size_t			dongle_cooldown;
	char			*scheduler;
}					t_args;

typedef struct s_sim_info
{
	struct timespec	started_at;
	t_args			args;
	pthread_mutex_t	log_mutex;
	int				log_mutex_init;
}					t_sim_info;

void				args_debug(t_args args);
int					args_parse(t_args *args, int argc, char **argv);

#endif
