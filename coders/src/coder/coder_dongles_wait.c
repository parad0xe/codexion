/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongles_wait.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:51:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/31 15:16:10 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"
#include "heapq.h"
#include "utils.h"
#include <pthread.h>
#include <unistd.h>

static void	_dequeue_both_thread_unsafe(t_coder *coder, t_dongle *first,
		t_dongle *second)
{
	t_heapq_data	*queued_coder;

	queued_coder = heapq_peek(first->queue);
	if (queued_coder != NULL && queued_coder->data == coder)
		heapq_dequeue(first->queue);
	queued_coder = heapq_peek(second->queue);
	if (queued_coder != NULL && queued_coder->data == coder)
		heapq_dequeue(second->queue);
}

static void	_enqueue_both_thread_safe(t_coder *coder, t_dongle *first,
		t_dongle *second)
{
	pthread_mutex_lock(&first->access_mutex);
	heapq_enqueue(first->queue, coder, coder_get_priority(coder));
	pthread_mutex_unlock(&first->access_mutex);
	pthread_mutex_lock(&second->access_mutex);
	heapq_enqueue(second->queue, coder, coder_get_priority(coder));
	pthread_mutex_unlock(&second->access_mutex);
}

static int	_can_acquire_dongle(t_coder *coder, t_dongle *dongle)
{
	t_heapq_data	*queued_coder;

	if (dongle->is_available == 0)
		return (0);
	queued_coder = heapq_peek(dongle->queue);
	if (queued_coder != NULL && queued_coder->data != coder
		&& queued_coder->priority <= coder_get_priority(coder))
		return (0);
	return (1);
}

static int	_attempt_acquire(t_coder *coder, t_dongle *first, t_dongle *second)
{
	t_dongle	*wait_dongle;

	pthread_mutex_lock(&first->access_mutex);
	pthread_mutex_lock(&second->access_mutex);
	if (_can_acquire_dongle(coder, first) && _can_acquire_dongle(coder, second))
	{
		_dequeue_both_thread_unsafe(coder, first, second);
		dongle_thread_unsafe_acquire(first);
		dongle_thread_unsafe_acquire(second);
		pthread_mutex_unlock(&second->access_mutex);
		pthread_mutex_unlock(&first->access_mutex);
		return (1);
	}
	wait_dongle = first;
	if (_can_acquire_dongle(coder, first))
		wait_dongle = second;
	if (wait_dongle == first)
		pthread_mutex_unlock(&second->access_mutex);
	else
		pthread_mutex_unlock(&first->access_mutex);
	pthread_cond_timedwait(&wait_dongle->access_cond,
		&wait_dongle->access_mutex, &coder->burnout_at);
	pthread_mutex_unlock(&wait_dongle->access_mutex);
	return (0);
}

int	coder_dongles_wait(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	first = coder->left_dongle;
	second = coder->right_dongle;
	if (second == NULL)
		time_sleep_ms(coder->time_to_burnout);
	if (second == NULL)
		return (0);
	if (coder->id % 2 != 0)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	_enqueue_both_thread_safe(coder, first, second);
	while (!coder_has_burnout(coder))
	{
		if (_attempt_acquire(coder, first, second))
		{
			dongle_wait_cooldown(first);
			dongle_wait_cooldown(second);
			return (!coder_has_burnout(coder));
		}
	}
	return (0);
}
