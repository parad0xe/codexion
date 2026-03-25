/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:35:30 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 17:51:08 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# define ERR_MALLOC 1
# define ERR_THREAD_CREATE 2
# define ERR_THREAD_JOIN 3

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
