/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_routine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:45:14 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 12:52:23 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	*coder_routine(void *thread_args)
{
	t_coder	*coder;
	size_t	i;

	coder = (t_coder *)thread_args;
	coder_sync(coder);
	i = 0;
	while (i < coder->number_of_compiles)
	{
		if (coder_dongles_wait(coder))
		{
			coder_compile(coder);
			coder_dongles_release(coder);
			coder_debug(coder);
			coder_refactor(coder);
		}
		else
		{
			coder_die(coder);
			break ;
		}
		i++;
	}
	return (NULL);
}
