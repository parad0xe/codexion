/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_manager_pool_destroy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 10:03:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:16:14 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include <pthread.h>
#include <stdlib.h>

void	dmp_destroy(t_dongle_manager_pool **pool)
{
	if (*pool == NULL)
		return ;
	pthread_mutex_destroy(&(*pool)->shared_mutex);
	dongle_managers_destroy(&(*pool)->managers);
	dongles_destroy(&(*pool)->dongles, (*pool)->count);
	free(*pool);
	*pool = NULL;
}
