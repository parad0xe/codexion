/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:19:43 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/26 19:59:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	absmod(int n, int mod)
{
	int	remainder;

	remainder = n % mod;
	if (remainder < 0)
		return (remainder + mod);
	return (remainder);
}
