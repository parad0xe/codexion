/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_lifecycle_destroy.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:41:10 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 13:58:30 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

static void	_test_dongle_destroy(void)
{
	t_dongle	*dongles;
	size_t		size;

	test_group("test dongles destroy");
	size = 5;
	dongles = dongle_create(size, 10);
	assert_is_not_null("handle valid array of dongles creation", dongles);
	dongle_destroy(&dongles, size);
	assert_is_null("handle pointer reset to null after destroy", dongles);
	dongle_destroy(&dongles, size);
	assert_is_null("handle already null pointer safely", dongles);
}

int	main(void)
{
	_test_dongle_destroy();
	return (0);
}
