/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:45:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:25:00 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include <stdlib.h>

void	coders_destroy(t_coder **coders)
{
	if (*coders == NULL)
		return ;
	free(*coders);
	*coders = NULL;
	return ;
}
