/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_lifecycle_destroy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:10:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:08:12 by nlallema         ###   ########lyon.fr   */
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
	if ((*workspace)->dongles != NULL)
		dongle_destroy(&(*workspace)->dongles,
			(*workspace)->coders->count);
	if ((*workspace)->coders != NULL)
		coder_destroy(&(*workspace)->coders);
	free(*workspace);
	*workspace = NULL;
	return ;
}
