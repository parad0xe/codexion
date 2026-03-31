/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_action_release.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:14:17 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 15:14:29 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include <pthread.h>

void	dongle_thread_safe_release(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->access_mutex);
	dongle->is_available = 1;
	time_set_abstimeout(&dongle->available_at, dongle->cooldown);
	pthread_mutex_unlock(&dongle->access_mutex);
	pthread_cond_broadcast(&dongle->access_cond);
}
