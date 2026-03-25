/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:19:43 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 14:34:04 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_mod(int n, int mod)
{
	int	remainder;

	remainder = n % mod;
	if (remainder < 0)
		return (remainder + mod);
	return (remainder);
}
