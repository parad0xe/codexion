/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_compile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:03:46 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:50:02 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <unistd.h>

void	coder_compile(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	log_thread_safe(coder, "is compiling", LOG_IF_RUNNING);
	time_set_abstimeout(&coder->burnout_at, coder->sim->args.time_to_burnout);
	coder->compilation_count += 1;
	time_sleep_ms(coder->sim->args.time_to_compile);
}
