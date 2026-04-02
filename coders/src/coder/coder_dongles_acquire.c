/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongles_acquire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:28:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:06:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"

void	coder_dongles_acquire_thread_unsafe(t_coder *coder)
{
	if (coder_is_running_thread_safe(coder))
	{
		dongle_thread_unsafe_acquire(coder->left_dongle);
		log_thread_safe(coder, "has taken a dongle", LOG_IF_RUNNING);
		dongle_thread_unsafe_acquire(coder->right_dongle);
		log_thread_safe(coder, "has taken a dongle", LOG_IF_RUNNING);
	}
}
