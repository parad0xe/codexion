/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_get_priority.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:12:50 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:43:54 by nlallema         ###   ########lyon.fr   */
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
		priority = coder->last_compile_start + coder->time_to_burnout;
	return (priority);
}
