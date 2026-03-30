/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongles_release.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:15:07 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:59:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>

static void	_coder_dongle_release(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->access_mutex);
	dongle->is_available = 1;
	time_set_abstimeout(&dongle->available_at, dongle->cooldown);
	pthread_mutex_unlock(&dongle->access_mutex);
	pthread_cond_broadcast(&dongle->access_cond);
}

void	coder_dongles_release(t_coder *coder)
{
	_coder_dongle_release(coder->left_dongle);
	printf("coder %d release left dongle\n", coder->id);
	_coder_dongle_release(coder->right_dongle);
	printf("coder %d release right dongle\n", coder->id);
}
