/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:49:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 14:07:36 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODERS_H
# define CODERS_H

# include "codexion.h"
# include "dongle.h"
# include <pthread.h>

typedef struct s_coder
{
	pthread_t	tid;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
}				t_coder;

typedef struct s_coders
{
	t_coder		*coders;
	t_dongle	*dongles;
}				t_coders;

int				coders_init(t_coders *coders, t_args *args);
void			coders_destroy(t_coders *coders);
void			*coder_routine(void *thread_args);
int				coders_thread_start(t_coders *coders, t_args *args);
int				coders_thread_join(t_coders *coders, t_args *args);
void			debug_coders(t_coders *coders, t_args *args);

#endif
