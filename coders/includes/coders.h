/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:49:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 16:58:58 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODERS_H
# define CODERS_H

# include "codexion.h"
# include "dongle.h"
# include <pthread.h>

typedef struct s_coder
{
	pthread_t				tid;
	t_dongle_manager		*dongle_manager;
	size_t					time_to_burnout;
	size_t					time_to_compile;
	size_t					time_to_debug;
	size_t					time_to_refactor;
	size_t					number_of_compiles;
}							t_coder;

typedef struct s_workspace
{
	t_coder					*coders;
	t_dongle_manager_pool	*manager_pool;
}							t_workspace;

t_coder						*coders_create(t_args *args,
								t_dongle_manager_pool *pool);
void						coders_destroy(t_coder **coders, size_t count);

#endif
