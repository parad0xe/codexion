/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_priority.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:12:50 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:52:14 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stddef.h>
#include <string.h>

size_t	coder_get_priority(t_coder *coder)
{
	size_t	priority;

	priority = 0;
	if (strcmp(coder->scheduler, "edf") == 0)
		priority = coder_get_burnout_at(coder);
	return (priority);
}
