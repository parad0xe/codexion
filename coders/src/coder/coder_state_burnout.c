/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_state_burnout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:12:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 16:57:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"

size_t	coder_get_burnout_at(t_coder *coder)
{
	return (time_convert_timespec_to_ms(&coder->burnout_at));
}

int	coder_has_burnout(t_coder *coder)
{
	int	has_burnout;

	has_burnout = time_get_current_ms() >= coder_get_burnout_at(coder);
	return (has_burnout);
}
