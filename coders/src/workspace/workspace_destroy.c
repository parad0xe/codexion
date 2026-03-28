/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:10:12 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 18:13:34 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "dongle.h"
#include "workspace.h"
#include <stdlib.h>

void	workspace_destroy(t_workspace **workspace)
{
	if (*workspace == NULL)
		return ;
	if ((*workspace)->coders != NULL)
		coders_destroy(&(*workspace)->coders, (*workspace)->coder_count);
	if ((*workspace)->manager_pool != NULL)
		dmp_destroy(&(*workspace)->manager_pool);
	free(*workspace);
	*workspace = NULL;
	return ;
}
