/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:36 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:21:58 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "heapq.h"
#include <stddef.h>
#include <stdlib.h>

void	dongles_destroy(t_dongle **dongles, size_t count)
{
	size_t	i;

	if (*dongles == NULL)
		return ;
	i = 0;
	while (i < count)
	{
		if ((*dongles)[i].queue != NULL)
			heapq_destroy(&(*dongles)[i].queue);
		i++;
	}
	free(*dongles);
	(*dongles) = NULL;
}
