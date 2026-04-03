/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action_compile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:03:46 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/03 14:38:07 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "utils.h"
#include <pthread.h>
#include <unistd.h>

/**
 * @brief Executes the compilation action and resets the burnout timer.
 *
 * @param coder Entity executing the compilation action
 */
void	coder_compile(t_coder *coder)
{
	unsigned int	sleep_ms;

	if (!coder_is_running_thread_safe(coder))
		return ;
	coder_reset_burnout_at_thread_safe(coder);
	coder_log_thread_safe(coder, "is compiling", LOG_IF_RUNNING);
	pthread_mutex_lock(&coder->access_mutex);
	coder->compilation_count += 1;
	sleep_ms = coder->sim->args.time_to_compile;
	pthread_mutex_unlock(&coder->access_mutex);
	time_sleep_ms(sleep_ms);
}
