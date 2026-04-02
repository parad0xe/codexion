/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:20:28 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 12:03:31 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "coder.h"
# include <stddef.h>
# include <sys/time.h>

# define LOG_ALWAYS 0
# define LOG_IF_RUNNING 1

// math
int		math_absmod(int n, int mod);

// time
void	time_sleep_ms(size_t ms);
size_t	time_get_current_ms(void);
void	time_set_abstimeout(struct timespec *ts, size_t timeout);
size_t	time_convert_timespec_to_ms(struct timespec *ts);
size_t	time_get_elapsed_ms(struct timespec *ts);

// log
void	log_thread_safe(t_coder *coder, char *message,
			int check_running);

#endif
