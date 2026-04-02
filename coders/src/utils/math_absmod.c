/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_absmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:19:43 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:26:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Calculates the strictly positive modulo of a given number.
 *
 * @param n Number to be evaluated
 * @param mod Modulo divisor to apply
 * @return The strictly positive remainder
 */
int	math_absmod(int n, int mod)
{
	int	remainder;

	remainder = n % mod;
	if (remainder < 0)
		return (remainder + mod);
	return (remainder);
}
