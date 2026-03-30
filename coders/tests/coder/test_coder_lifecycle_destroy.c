/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_destroy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:16:40 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:46:49 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "test.h"
#include <stdlib.h>

int	main(void)
{
	t_coder	*coders;

	coders = malloc(sizeof(t_coder) * 2);
	custom_assert("allocate coders manually", coders != NULL);
	coder_destroy(&coders);
	custom_assert("set pointer to NULL after destroy", coders == NULL);
	coder_destroy(&coders);
	custom_assert("safely handle already NULL pointer", coders == NULL);
	return (0);
}
