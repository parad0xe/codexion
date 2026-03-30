/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_refactor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:06:53 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 17:54:03 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <unistd.h>

// create difference between fifo and edf on powerful pc
// usleep((coder->time_to_refactor + (rand() % 70)) * 1000);
void	coder_refactor(t_coder *coder)
{
	usleep(coder->time_to_refactor * 1000);
}
