/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_refactor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:53 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 17:01:27 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stdio.h>
#include <unistd.h>

// create difference between fifo and edf on powerful pc
// usleep((coder->time_to_refactor + (rand() % 70)) * 1000);
void	coder_refactor(t_coder *coder)
{
	if (!coder_is_running_thread_safe(coder))
		return ;
	printf("coder %d refactoring..\n", coder->id);
	usleep(coder->time_to_refactor * 1000);
}
