/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:04:57 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <unistd.h>

void	coder_debug(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	log_thread_safe(coder, "is debugging", LOG_IF_RUNNING);
	usleep(coder->sim->args.time_to_debug * 1000);
}
