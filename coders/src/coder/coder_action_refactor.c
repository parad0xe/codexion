/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_refactor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:53 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:50:28 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <unistd.h>

// create difference between fifo and edf on powerful pc
// usleep((coder->time_to_refactor + (rand() % 70)) * 1000);
void	coder_refactor(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	log_thread_safe(coder, "is refactoring", LOG_IF_RUNNING);
	time_sleep_ms(coder->sim->args.time_to_refactor);
}
