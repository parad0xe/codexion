/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_get_ready_timestamp.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:48:48 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 22:49:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"

size_t	dongle_get_ready_timestamp(t_dongle *dongle)
{
	return (dongle->last_usage + dongle->cooldown);
}
