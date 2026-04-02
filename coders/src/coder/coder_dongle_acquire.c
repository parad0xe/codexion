/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongle_acquire.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:28:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:40:49 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"

void	coder_dongle_acquire_thread_unsafe(t_coder *coder)
{
	if (coder_is_running_thread_safe(coder))
	{
		dongle_acquire_thread_unsafe(coder->left_dongle);
		coder_log_thread_safe(coder, "has taken a dongle", LOG_IF_RUNNING);
		dongle_acquire_thread_unsafe(coder->right_dongle);
		coder_log_thread_safe(coder, "has taken a dongle", LOG_IF_RUNNING);
	}
}
