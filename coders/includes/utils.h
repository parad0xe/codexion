/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:20:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/29 14:11:59 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <sys/time.h>

int		absmod(int n, int mod);
size_t	get_current_timestamp(void);
void	set_absolute_timeout(struct timespec *ts, size_t timeout);

#endif
