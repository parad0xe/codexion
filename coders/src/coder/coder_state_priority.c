/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_priority.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:12:50 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 11:48:29 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stddef.h>
#include <string.h>

size_t	coder_get_priority(t_coder *coder)
{
	size_t	priority;

	priority = 0;
	if (strcmp(coder->sim->args.scheduler, "edf") == 0)
		priority = coder_get_burnout_at(coder);
	return (priority);
}
