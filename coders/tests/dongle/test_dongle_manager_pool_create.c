/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_manager_pool_create.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:02:41 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:42:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

int	main(void)
{
	t_dongle_manager_pool	*pool;

	pool = dmp_create(4, 15);
	custom_assert("create valid pool", pool != NULL);
	custom_assert("set correct count", pool->count == 4);
	custom_assert("create dongles array", pool->dongles != NULL);
	custom_assert("create managers array", pool->managers != NULL);
	dmp_destroy(&pool);
	return (0);
}
