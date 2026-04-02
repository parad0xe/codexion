/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_action_acquire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:11:35 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:24:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"

/**
 * @brief Marks the dongle as unavailable without thread locking.
 *
 * @param dongle Target dongle to be acquired
 */
void	dongle_acquire_thread_unsafe(t_dongle *dongle)
{
	dongle->is_available = 0;
}
