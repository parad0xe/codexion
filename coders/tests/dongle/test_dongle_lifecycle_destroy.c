/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongle_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:41:10 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:47:30 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

int	main(void)
{
	t_dongle	*dongles;
	size_t		size;

	size = 5;
	dongles = dongle_create(size, 10);
	custom_assert("it should create a valid array of dongles", dongles != NULL);
	dongle_destroy(&dongles, size);
	custom_assert("it should set the dongles pointer to NULL after destroy",
		dongles == NULL);
	dongle_destroy(&dongles, size);
	custom_assert("it should safely handle destroying an already NULL pointer",
		dongles == NULL);
	return (0);
}
