/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:41:22 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 22:23:55 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

void	print_test_start(char *test_name);
void	print_test_ok(void);
void	print_test_ko(void);
void	custom_assert(char *message, int condition);

#endif
