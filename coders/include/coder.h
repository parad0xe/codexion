/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:49:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:52:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_H
# define CODER_H

# include "codexion.h"
# include "dongle.h"
# include <pthread.h>
# include <time.h>

typedef struct s_coder
{
	int				id;
	pthread_t		tid;
	t_sim_info		*sim;
	int				*can_start;
	pthread_cond_t	*start_cond;
	pthread_mutex_t	*start_mutex;
	int				is_running;
	pthread_mutex_t	is_running_mutex;
	int				is_running_mutex_init;
	size_t			compilation_count;
	struct timespec	burnout_at;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
}					t_coder;

typedef struct s_coder_array
{
	t_coder			*items;
	size_t			count;
	pthread_mutex_t	start_mutex;
	int				start_mutex_init;
	pthread_cond_t	start_cond;
	int				start_cond_init;
	int				can_start;
}					t_coder_array;

// lifecycle
t_coder_array		*coder_create(t_sim_info *sim, t_dongle *dongles);
void				coder_destroy(t_coder_array **coders);
void				*coder_routine(void *thread_args);

// dongles
int					coder_dongle_wait(t_coder *coder);
void				coder_dongle_release(t_coder *coder);
void				coder_dongle_acquire_thread_unsafe(t_coder *coder);

// actions
void				coder_sync(t_coder *coder);
void				coder_compile(t_coder *coder);
void				coder_debug(t_coder *coder);
void				coder_refactor(t_coder *coder);

// state
int					coder_has_burnout(t_coder *coder);
size_t				coder_get_burnout_at(t_coder *coder);
size_t				coder_get_priority(t_coder *coder);
int					coder_is_running_thread_safe(t_coder *coder);
void				coder_set_running_thread_safe(t_coder *coder,
						int is_running);

#endif
