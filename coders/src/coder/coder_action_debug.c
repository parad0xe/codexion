/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:15:03 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <unistd.h>

/**
 * @brief Puts the coder in a debugging state for a specified duration.
 *
 * @param coder Entity executing the debugging action
 */
void	coder_debug(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	coder_log_thread_safe(coder, "is debugging", LOG_IF_RUNNING);
	time_sleep_ms(coder->sim->args.time_to_debug);
}
