/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_debug.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:05 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 13:33:47 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stdio.h>
#include <unistd.h>

void	coder_debug(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	printf("coder %d debugging..\n", coder->id);
	usleep(coder->time_to_debug * 1000);
}
