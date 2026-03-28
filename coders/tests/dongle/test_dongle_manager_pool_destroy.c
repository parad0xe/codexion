/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_manager_pool_destroy.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:05:18 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:42:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

int	main(void)
{
	t_dongle_manager_pool	*pool;

	pool = dmp_create(3, 10);
	custom_assert("create valid pool", pool != NULL);
	dmp_destroy(&pool);
	custom_assert("pool pointer set to null", pool == NULL);
	dmp_destroy(&pool);
	custom_assert("handle double destroy safely", pool == NULL);
	return (0);
}
