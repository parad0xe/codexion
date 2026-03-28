/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:41:22 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/28 16:16:54 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

void	print_test_name(char *test_name);
void	print_test_loop_name(char *loop_name, int index);
void	print_test_ok(void);
void	print_test_ko(void);
void	custom_assert(char *message, int condition);

#endif
