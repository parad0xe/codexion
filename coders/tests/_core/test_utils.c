/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:40:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 16:20:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void	print_test_name(char *test_name)
{
	printf("\033[1;34m::\033[0m \033[0;36m%s...\033[0m ", test_name);
}

void	print_test_loop_name(char *loop_name, int index)
{
	printf("\n\033[1;35m>> %s [%d] <<\033[0m\n", loop_name, index);
}

void	print_test_ok(void)
{
	printf("\033[0;32m✔ test ok\033[0m\n");
}

void	print_test_ko(void)
{
	printf("\033[0;31m✘ test ko\033[0m\n");
}

void	custom_assert(char *message, int condition)
{
	print_test_name(message);
	if (!condition)
	{
		print_test_ko();
		exit(1);
	}
	else
		print_test_ok();
}
