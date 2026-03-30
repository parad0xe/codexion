/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_die.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:00:17 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 12:00:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include <stdio.h>
#include <stdlib.h>

void	coder_die(t_coder *coder)
{
	printf("coder %d BURNOUT\n", coder->id);
	exit(1);
}
