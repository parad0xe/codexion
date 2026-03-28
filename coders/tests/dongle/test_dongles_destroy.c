/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dongles_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:41:10 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 11:42:44 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dongle.h"
#include "test.h"

int	main(void)
{
	t_dongle	*dongles;
	size_t		size;

	size = 5;
	dongles = dongles_create(size, 10);
	custom_assert("it should create a valid array of dongles", dongles != NULL);
	dongles_destroy(&dongles, size);
	custom_assert("it should set the dongles pointer to NULL after destroy",
		dongles == NULL);
	dongles_destroy(&dongles, size);
	custom_assert("it should safely handle destroying an already NULL pointer",
		dongles == NULL);
	return (0);
}
