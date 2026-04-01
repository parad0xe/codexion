/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_compile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:03:46 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 13:33:29 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

void	coder_compile(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	printf("coder %d compiling..\n", coder->id);
	time_set_abstimeout(&coder->burnout_at, coder->time_to_burnout);
	usleep(coder->time_to_compile * 1000);
}
