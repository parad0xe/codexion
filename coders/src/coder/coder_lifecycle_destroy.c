/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_lifecycle_destroy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:43:49 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stdlib.h>

void	coder_destroy(t_coder **coders)
{
	if (*coders == NULL)
		return ;
	free(*coders);
	*coders = NULL;
	return ;
}
