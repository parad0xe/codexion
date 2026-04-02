/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_routine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:23:36 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Main execution loop for an individual coder thread.
 *
 * @param thread_args Pointer to the coder entity structure
 * @return NULL upon completion
 */
void	*coder_routine(void *thread_args)
{
	t_coder	*coder;
	size_t	i;

	coder = (t_coder *)thread_args;
	coder_sync(coder);
	i = 0;
	while (1)
	{
		if (!coder_is_running_thread_safe(coder))
			break ;
		if (coder_dongle_wait(coder))
		{
			if (!coder_is_running_thread_safe(coder))
				break ;
			coder_compile(coder);
			coder_dongle_release_thread_safe(coder);
			coder_debug(coder);
			coder_refactor(coder);
		}
		else
			break ;
		i++;
	}
	return (NULL);
}
