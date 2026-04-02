/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:14:08 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 13:26:35 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

void	assert_is_null(char *message, void *ptr)
{
	custom_assert(message, ptr == NULL);
}

void	assert_is_not_null(char *message, void *ptr)
{
	custom_assert(message, ptr != NULL);
}
