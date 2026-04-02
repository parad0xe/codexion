/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:20:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 13:26:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <sys/time.h>

// math
int		math_absmod(int n, int mod);

// time
void	time_sleep_ms(size_t ms);
size_t	time_get_current_ms(void);
void	time_set_abstimeout(struct timespec *ts, size_t timeout);
size_t	time_convert_timespec_to_ms(struct timespec *ts);
size_t	time_get_elapsed_ms(struct timespec *ts);

#endif
