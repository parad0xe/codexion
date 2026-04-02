/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_dongle_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:51:31 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 21:40:25 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "codexion.h"
#include "dongle.h"
#include "heapq.h"
#include "utils.h"
#include <pthread.h>
#include <unistd.h>

/**
 * @brief Removes the coder from both requested dongle queues.
 *
 * @param coder Entity being removed from the queues
 * @param first Pointer to the first dongle queue
 * @param second Pointer to the second dongle queue
 */
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

/**
 * @brief Safely adds the coder to both requested dongle queues.
 *
 * @param coder Entity being added to the queues
 * @param first Pointer to the first dongle queue
 * @param second Pointer to the second dongle queue
 */
static void	_enqueue_both_thread_safe(t_coder *coder, t_dongle *first,
		t_dongle *second)
{
	t_errcode	errcode;

	pthread_mutex_lock(&first->access_mutex);
	errcode = heapq_enqueue(first->queue, coder, coder_get_priority(coder));
	if (errcode != 0)
		coder->sim->errcode = errcode;
	pthread_mutex_unlock(&first->access_mutex);
	pthread_mutex_lock(&second->access_mutex);
	errcode = heapq_enqueue(second->queue, coder, coder_get_priority(coder));
	if (errcode != 0)
		coder->sim->errcode = errcode;
	pthread_mutex_unlock(&second->access_mutex);
}

/**
 * @brief Checks if the given dongle is available and the coder has priority.
 *
 * @param coder Entity attempting to acquire the dongle
 * @param dongle Target dongle to evaluate
 * @return 1 if the dongle can be acquired, 0 otherwise
 */
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

/**
 * @brief Evaluates dongle availability and attempts simultaneous lock.
 *
 * @param coder Entity attempting to acquire both dongles
 * @param first First dongle to lock
 * @param second Second dongle to lock
 * @return 1 if both dongles are successfully acquired, 0 otherwise
 */
static int	_attempt_acquire(t_coder *coder, t_dongle *first, t_dongle *second)
{
	t_dongle	*wait_dongle;

	pthread_mutex_lock(&first->access_mutex);
	pthread_mutex_lock(&second->access_mutex);
	if (_can_acquire_dongle(coder, first) && _can_acquire_dongle(coder, second))
	{
		_dequeue_both_thread_unsafe(coder, first, second);
		coder_dongle_acquire_thread_unsafe(coder);
		pthread_mutex_unlock(&second->access_mutex);
		pthread_mutex_unlock(&first->access_mutex);
		return (coder_is_running_thread_safe(coder));
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

/**
 * @brief Puts the coder in a waiting queue to acquire both required dongles.
 *
 * @param coder The coder entity attempting to acquire dongles
 * @return 1 if acquired successfully, 0 if a burnout occurred
 */
int	coder_dongle_wait(t_coder *coder)
{
	t_dongle	*first;
	t_dongle	*second;

	first = coder->left_dongle;
	second = coder->right_dongle;
	if (second == NULL)
		time_sleep_ms(coder->sim->args.time_to_burnout);
	if (second == NULL)
		return (0);
	if (coder->id % 2 != 0)
	{
		first = coder->right_dongle;
		second = coder->left_dongle;
	}
	_enqueue_both_thread_safe(coder, first, second);
	while (!coder_has_burnout(coder) && coder_is_running_thread_safe(coder))
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
