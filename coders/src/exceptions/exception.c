/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:03:53 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 21:56:49 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "codexion.h"

/**
 * @brief Evaluates an error code and routes it to the specific module.
 *
 * @param errcode The error code to evaluate
 * @return The exact same error code passed as parameter
 */
t_errcode	exception(t_errcode errcode)
{
	if (errcode == 0)
		return (0);
	if (errcode < 10)
		exception_sys(errcode);
	else if (errcode < 20)
		exception_args(errcode);
	else if (errcode < 30)
		exception_dongle(errcode);
	else if (errcode < 40)
		exception_coder(errcode);
	else if (errcode < 50)
		exception_workspace(errcode);
	else if (errcode < 60)
		exception_sim(errcode);
	else
		exception_heapq(errcode);
	return (errcode);
}
