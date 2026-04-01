/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:44:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 13:32:11 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>

int	coder_is_running_thread_safe(t_coder *coder)
{
	int	is_running;

	pthread_mutex_lock(&coder->is_running_mutex);
	is_running = coder->is_running;
	pthread_mutex_unlock(&coder->is_running_mutex);
	return (is_running);
}

void	coder_set_running_thread_safe(t_coder *coder, int is_running)
{
	pthread_mutex_lock(&coder->is_running_mutex);
	coder->is_running = is_running;
	pthread_mutex_unlock(&coder->is_running_mutex);
}
