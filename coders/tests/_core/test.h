/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:41:22 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 13:47:27 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

void	test_group(char *title);
void	test_loop_group(char *title, int index);
void	test_ok(void);
void	test_ko(void);
void	custom_assert(char *message, int condition);

// asserts
void	assert_is_null(char *message, void *ptr);
void	assert_is_not_null(char *message, void *ptr);

#endif
