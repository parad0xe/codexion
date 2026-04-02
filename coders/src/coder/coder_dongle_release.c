/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongle_release.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:15:07 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:41:21 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"

void	coder_dongle_release(t_coder *coder)
{
	dongle_release_thread_safe(coder->left_dongle);
	dongle_release_thread_safe(coder->right_dongle);
}
