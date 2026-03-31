/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_action_acquire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:11:35 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 15:14:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"

void	dongle_thread_unsafe_acquire(t_dongle *dongle)
{
	dongle->is_available = 0;
}
