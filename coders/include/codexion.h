/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:35:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:28:35 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stddef.h>
# include <time.h>

// project-side errors
# define ERR_THREAD_CREATE 1
# define ERR_THREAD_JOIN 2

// argument errors
# define ERR_ARGS_MISMATCH 10
# define ERR_ARG_INVALID_UINT 11
# define ERR_ARG_SCHEDULER 12

// dongle errors
# define ERR_DONGLE_MALLOC 20
# define ERR_DONGLE_MUTEX_INIT 21
# define ERR_DONGLE_COND_INIT 22

// coder errors
# define ERR_CODER_MALLOC 30
# define ERR_CODER_ITEMS_MALLOC 31
# define ERR_CODER_MUTEX_INIT 32
# define ERR_CODER_COND_INIT 33

// workspace errors
# define ERR_WORKSPACE_MALLOC 40

// sim errors
# define ERR_SIM_MUTEX_INIT 50

// heapq errors
# define ERR_HEAPQ_MALLOC 60
# define ERR_HEAPQ_NULL 61

typedef int			t_errcode;

typedef struct s_args
{
	unsigned int	number_of_coders;
	unsigned int	time_to_burnout;
	unsigned int	time_to_compile;
	unsigned int	time_to_debug;
	unsigned int	time_to_refactor;
	unsigned int	number_of_compiles;
	unsigned int	dongle_cooldown;
	char			*scheduler;
}					t_args;

typedef struct s_sim_info
{
	struct timespec	started_at;
	t_args			args;
	pthread_mutex_t	log_mutex;
	int				log_mutex_init;
	t_errcode		errcode;
}					t_sim_info;

void				args_debug(t_args args);
int					args_parse(t_sim_info *sim, int argc, char **argv);

#endif
