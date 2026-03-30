/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_destroy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:10:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:45:06 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"
#include "workspace.h"
#include <pthread.h>
#include <stdlib.h>

void	workspace_destroy(t_workspace **workspace)
{
	if (*workspace == NULL)
		return ;
	if ((*workspace)->start_mutex_init)
		pthread_mutex_destroy(&(*workspace)->start_mutex);
	if ((*workspace)->coders != NULL)
		coder_destroy(&(*workspace)->coders);
	if ((*workspace)->dongles != NULL)
		dongle_destroy(&(*workspace)->dongles, (*workspace)->coder_count);
	free(*workspace);
	*workspace = NULL;
	return ;
}
