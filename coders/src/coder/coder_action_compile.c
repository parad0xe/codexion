/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_compile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:03:46 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:55:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

void	coder_compile(t_coder *coder)
{
	printf("coder %d acquire dongles\n", coder->id);
	time_set_abstimeout(&coder->burnout_at, coder->time_to_burnout);
	usleep(coder->time_to_compile * 1000);
}
