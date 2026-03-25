/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:50:04 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 13:40:21 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DONGLE_H
# define DONGLE_H

# include <pthread.h>

typedef struct s_dongle
{
	int				cooldown;
	pthread_mutex_t	cooldown_mutex;
}					t_dongle;

#endif
