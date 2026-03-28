/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_managers_destroy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:01:45 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:57:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"
#include <pthread.h>

int	main(void)
{
	t_dongle_manager	*managers;
	t_dongle			*dongles;
	pthread_mutex_t		mutex;

	pthread_mutex_init(&mutex, NULL);
	dongles = dongles_create(2, 10);
	managers = dongle_managers_create(&mutex, dongles, 2, 10);
	dongle_managers_destroy(&managers, 2);
	custom_assert("managers pointer set to null", managers == NULL);
	dongle_managers_destroy(&managers, 2);
	custom_assert("handle already null pointer", managers == NULL);
	dongles_destroy(&dongles, 2);
	pthread_mutex_destroy(&mutex);
	return (0);
}
