/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:40:16 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 14:09:53 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void	test_group(char *title)
{
	printf("\n\033[1;35m>> %s <<\033[0m\n", title);
}

void	test_loop_group(char *title, int index)
{
	printf("\n\033[0;35m:: %s [%d]\033[0m\n", title, index);
}

void	test_ok(void)
{
	printf("\033[0;32m✔ test ok\033[0m\n");
}

void	test_ko(void)
{
	printf("\033[0;31m✘ test ko\033[0m\n");
}

void	custom_assert(char *message, int condition)
{
	printf("  \033[1;34m::\033[0m \033[0;36m%s...\033[0m ", message);
	if (!condition)
	{
		test_ko();
		exit(1);
	}
	else
		test_ok();
}
