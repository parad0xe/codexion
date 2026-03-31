/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:29:30 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>
#include <stdlib.h>

void	coder_destroy(t_coder_array **coders)
{
	if (*coders == NULL)
		return ;
	if ((*coders)->start_mutex_init)
		pthread_mutex_destroy(&(*coders)->start_mutex);
	if ((*coders)->start_cond_init)
		pthread_cond_destroy(&(*coders)->start_cond);
	if ((*coders)->items != NULL)
		free((*coders)->items);
	free(*coders);
	*coders = NULL;
	return ;
}
