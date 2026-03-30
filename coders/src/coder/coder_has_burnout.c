/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_has_burnout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:12:39 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:44:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"

int	coder_has_burnout(t_coder *coder)
{
	int	has_burnout;

	has_burnout = get_current_timestamp() >= coder->last_compile_start
		+ coder->time_to_burnout;
	return (has_burnout);
}
