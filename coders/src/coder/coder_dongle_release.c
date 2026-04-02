/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongle_release.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:15:07 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 14:19:33 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"

/**
 * @brief Safely releases both left and right dongles held by the coder.
 *
 * @param coder Entity releasing its currently held dongles
 */
void	coder_dongle_release_thread_safe(t_coder *coder)
{
	dongle_release_thread_safe(coder->left_dongle);
	dongle_release_thread_safe(coder->right_dongle);
}
