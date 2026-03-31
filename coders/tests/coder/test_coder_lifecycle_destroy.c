/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_destroy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:16:40 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 12:35:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	t_coder_array	*coders;

	coders = malloc(sizeof(t_coder_array));
	memset(coders, 0, sizeof(t_coder_array));
	custom_assert("allocate coders manually", coders != NULL);
	coder_destroy(&coders);
	custom_assert("set pointer to NULL after destroy", coders == NULL);
	coder_destroy(&coders);
	custom_assert("safely handle already NULL pointer", coders == NULL);
	return (0);
}
