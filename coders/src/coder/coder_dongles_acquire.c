/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongles_acquire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:28:00 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/01 13:34:03 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stdio.h>

void	coder_dongles_acquire_thread_unsafe(t_coder *coder)
{
	if (coder_is_running_thread_safe(coder))
	{
		dongle_thread_unsafe_acquire(coder->left_dongle);
		printf("coder %d acquire left dongle\n", coder->id);
		dongle_thread_unsafe_acquire(coder->right_dongle);
		printf("coder %d acquire right dongles\n", coder->id);
	}
}
