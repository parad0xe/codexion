/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:04:44 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:12:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSPACE_H
# define WORKSPACE_H

# include "coders.h"
# include "dongle.h"
# include <stddef.h>

typedef struct s_workspace
{
	t_coder					*coders;
	t_dongle_manager_pool	*manager_pool;
	size_t					coder_count;
}							t_workspace;

t_workspace					*workspace_create(t_args *args);
void						workspace_destroy(t_workspace **workspace);

#endif
