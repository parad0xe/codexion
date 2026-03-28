/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:35:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 10:24:13 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

// project-side errors
# define ERR_MALLOC 1
# define ERR_THREAD_CREATE 2
# define ERR_THREAD_JOIN 3
# define ERR_MUTEX_INIT 4

// heapq errors
# define ERR_HEAPQ_MALLOC 10

// dongle errors
# define ERR_DONGLE_MALLOC 20
# define ERR_DONGLE_MANAGER_MALLOC 21

typedef int	t_errcode;

typedef struct s_args
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles;
	int		dongle_cooldown;
	char	*scheduler;
}			t_args;

#endif
