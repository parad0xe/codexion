/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:58:19 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "heapq.h"
#include <stddef.h>
#include <stdlib.h>

void	dongles_destroy(t_dongle **dongles, size_t count)
{
	int	i;

	if (*dongles == NULL)
		return ;
	i = -1;
	while (++i < count)
	{
		if ((*dongles)[i].queue == NULL)
			continue ;
		heapq_destroy(&(*dongles)[i].queue);
	}
	free(*dongles);
	(*dongles) = NULL;
}
