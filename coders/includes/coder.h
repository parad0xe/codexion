/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:49:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:54:33 by nlallema         ###   ########lyon.fr   */
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
	pthread_mutex_t	*start_mutex;
	size_t			time_to_burnout;
	size_t			time_to_compile;
	size_t			time_to_debug;
	size_t			time_to_refactor;
	size_t			number_of_compiles;
	struct timespec	burnout_at;
	char			*scheduler;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
}					t_coder;

// lifecycle
t_coder				*coder_create(t_args *args, t_dongle *dongles,
						pthread_mutex_t *start_mutex);
void				coder_destroy(t_coder **coders);
void				*coder_routine(void *thread_args);

// dongles
int					coder_dongles_wait(t_coder *coder);
void				coder_dongles_release(t_coder *coder);

// actions
void				coder_sync(t_coder *coder);
void				coder_die(t_coder *coder);
void				coder_compile(t_coder *coder);
void				coder_debug(t_coder *coder);
void				coder_refactor(t_coder *coder);

// state
int					coder_has_burnout(t_coder *coder);
size_t				coder_get_burnout_at(t_coder *coder);
size_t				coder_get_priority(t_coder *coder);

#endif
