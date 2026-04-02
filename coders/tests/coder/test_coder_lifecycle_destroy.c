/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_coder_lifecycle_destroy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:16:40 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:13:15 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

static void	_test_coder_destroy(void)
{
	t_coder_array	*coders;

	test_group("test coders destroy");
	coders = malloc(sizeof(t_coder_array));
	memset(coders, 0, sizeof(t_coder_array));
	assert_is_not_null("handle manual coders allocation", coders);
	coder_destroy(&coders);
	assert_is_null("handle pointer reset to null after destroy", coders);
	coder_destroy(&coders);
	assert_is_null("handle already null pointer safely", coders);
}

int	main(void)
{
	_test_coder_destroy();
	return (0);
}
