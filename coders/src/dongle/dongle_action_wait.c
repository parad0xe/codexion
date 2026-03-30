/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_action_wait.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:12:41 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:35:39 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "utils.h"
#include <unistd.h>

void	dongle_wait_cooldown(t_dongle *dongle)
{
	size_t	ready_at;

	ready_at = dongle_get_ready_at(dongle);
	if (ready_at > time_get_current_ms())
		time_sleep_ms(ready_at - time_get_current_ms());
}
