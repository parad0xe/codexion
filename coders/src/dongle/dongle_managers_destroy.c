/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_managers_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:48:13 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 10:16:34 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include <stdlib.h>

void	dongle_managers_destroy(t_dongle_manager **managers,
		size_t dongle_count)
{
	if (*managers == NULL)
		return ;
	free(*managers);
	*managers = NULL;
}
