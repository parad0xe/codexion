/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:25:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>
#include <stdlib.h>

/**
 * @brief Frees all allocated memory and destroys mutexes for the coders.
 *
 * @param coders Pointer to the coder array structure to destroy
 */
void	coder_destroy(t_coder_array **coders)
{
	size_t	i;

	if (*coders == NULL)
		return ;
	if ((*coders)->start_mutex_init)
		pthread_mutex_destroy(&(*coders)->start_mutex);
	if ((*coders)->start_cond_init)
		pthread_cond_destroy(&(*coders)->start_cond);
	i = 0;
	while (i < (*coders)->count)
	{
		if ((*coders)->items[i].access_mutex_init)
			pthread_mutex_destroy(&(*coders)->items[i].access_mutex);
		i++;
	}
	if ((*coders)->items != NULL)
		free((*coders)->items);
	free(*coders);
	*coders = NULL;
	return ;
}
