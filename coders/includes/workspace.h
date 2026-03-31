/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:04:44 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:05:36 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSPACE_H
# define WORKSPACE_H

# include "coder.h"
# include "dongle.h"
# include <pthread.h>
# include <stddef.h>

typedef struct s_workspace
{
	t_coder_array	*coders;
	t_dongle		*dongles;
}					t_workspace;

// lifecycle
t_workspace			*workspace_create(t_args *args);
void				workspace_destroy(t_workspace **workspace);

// thread actions
void				workspace_thread_start(t_workspace *workspace);
void				workspace_thread_join(t_workspace *workspace);

#endif
