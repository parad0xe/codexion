/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_wait_dongles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:51:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/30 11:44:13 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "dongle.h"
#include "heapq.h"
#include "utils.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>

static void	_dequeue_request(t_coder *coder, t_dongle *dongle)
{
	t_heapq_data	*queued_coder;

	queued_coder = heapq_peek(dongle->queue);
	if (queued_coder != NULL && queued_coder->data == coder)
		heapq_dequeue(dongle->queue);
}

static void	_enqueue_both(t_coder *coder, t_dongle *first, t_dongle *second)
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
	t_dongle	*target;

	pthread_mutex_lock(&first->access_mutex);
	pthread_mutex_lock(&second->access_mutex);
	if (_can_acquire_dongle(coder, first) && _can_acquire_dongle(coder, second))
	{
		_dequeue_request(coder, first);
		_dequeue_request(coder, second);
		first->is_available = 0;
		second->is_available = 0;
		pthread_mutex_unlock(&second->access_mutex);
		pthread_mutex_unlock(&first->access_mutex);
		return (1);
	}
	target = first;
	if (_can_acquire_dongle(coder, first))
		target = second;
	if (target == first)
		pthread_mutex_unlock(&second->access_mutex);
	else
		pthread_mutex_unlock(&first->access_mutex);
	pthread_cond_timedwait(&target->access_cond, &target->access_mutex,
		&coder->burnout_at);
	pthread_mutex_unlock(&target->access_mutex);
	return (0);
}

// todo: add support if one coder
int	coder_wait_dongles(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;
	size_t		max_ready;

	first = coder->left_dongle;
	second = coder->right_dongle;
	if (coder->id % 2 != 0)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	_enqueue_both(coder, first, second);
	while (!coder_has_burnout(coder))
	{
		if (_attempt_acquire(coder, first, second))
		{
			max_ready = dongle_get_ready_timestamp(first);
			if (dongle_get_ready_timestamp(second) > max_ready)
				max_ready = dongle_get_ready_timestamp(second);
			if (max_ready > get_current_timestamp())
				usleep((max_ready - get_current_timestamp()) * 1000);
			return (!coder_has_burnout(coder));
		}
	}
	return (0);
}
