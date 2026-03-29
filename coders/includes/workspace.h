/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:04:44 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 01:35:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSPACE_H
# define WORKSPACE_H

# include "coders.h"
# include "dongle.h"
# include <pthread.h>
# include <stddef.h>

typedef struct s_workspace
{
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	start_mutex;
	int				start_mutex_init;
	size_t			coder_count;
}					t_workspace;

t_workspace			*workspace_create(t_args *args);
void				workspace_destroy(t_workspace **workspace);

void				workspace_start(t_workspace *workspace);
void				workspace_join(t_workspace *workspace);

#endif
