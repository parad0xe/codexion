/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_managers_create.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 10:46:34 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 19:24:17 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"
#include <pthread.h>

static void	_test_assign(pthread_mutex_t *mutex, t_dongle_manager *managers,
		t_dongle *dongles)
{
	custom_assert("create valid managers array", managers != NULL);
	custom_assert("assign shared mutex [0]", managers[0].shared_mutex == mutex);
	custom_assert("assign left dongle [0]",
		managers[0].left_dongle == &dongles[0]);
	custom_assert("assign right dongle [0]",
		managers[0].right_dongle == &dongles[2]);
	custom_assert("assign shared mutex [1]", managers[1].shared_mutex == mutex);
	custom_assert("assign left dongle [1]",
		managers[1].left_dongle == &dongles[1]);
	custom_assert("assign right dongle [1]",
		managers[1].right_dongle == &dongles[0]);
	custom_assert("assign shared mutex [2]", managers[2].shared_mutex == mutex);
	custom_assert("assign left dongle [2]",
		managers[2].left_dongle == &dongles[2]);
	custom_assert("assign right dongle [2]",
		managers[2].right_dongle == &dongles[1]);
}

int	main(void)
{
	t_dongle_manager	*managers;
	t_dongle			*dongles;
	pthread_mutex_t		mutex;

	pthread_mutex_init(&mutex, NULL);
	dongles = dongles_create(3, 10);
	managers = dongle_managers_create(&mutex, dongles, 3);
	_test_assign(&mutex, managers, dongles);
	dongle_managers_destroy(&managers);
	dongles_destroy(&dongles, 3);
	pthread_mutex_destroy(&mutex);
	return (0);
}
