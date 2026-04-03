/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_action_release.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:14:17 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:05:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include <pthread.h>

/**
 * @brief Safely releases the dongle and notifies waiting threads.
 *
 * @param dongle Target dongle to be released
 */
void	dongle_release_thread_safe(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->access_mutex);
	dongle->is_available = 1;
	time_set_abstimeout(&dongle->available_at, dongle->cooldown);
	pthread_cond_broadcast(&dongle->access_cond);
	pthread_mutex_unlock(&dongle->access_mutex);
}
