/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:40:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 22:00:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void	print_test_start(char *test_name)
{
	printf("\033[0;36m:: testing %s...\033[0m ", test_name);
}

void	print_test_ok(void)
{
	printf("\033[0;32m✔ tests ok\033[0m\n");
}

void	print_test_ko(void)
{
	printf("\033[0;31m✘ ko\033[0m\n");
}

void	custom_assert(int condition)
{
	if (!condition)
	{
		print_test_ko();
		exit(1);
	}
}
