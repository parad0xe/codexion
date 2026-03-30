/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:19:43 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 13:30:23 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	math_absmod(int n, int mod)
{
	int	remainder;

	remainder = n % mod;
	if (remainder < 0)
		return (remainder + mod);
	return (remainder);
}
