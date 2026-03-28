/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:57:15 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 09:06:13 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include <stdlib.h>

void	heapq_destroy(t_heapq **heapq)
{
	int	i;

	if (*heapq == NULL)
		return ;
	if ((*heapq)->queue != NULL)
	{
		i = -1;
		while (++i < (*heapq)->count)
			free((*heapq)->queue[i]);
		free((*heapq)->queue);
	}
	free(*heapq);
	*heapq = NULL;
}
