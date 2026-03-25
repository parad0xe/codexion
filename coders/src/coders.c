/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:43 by nlallema          #+#    #+#             */
/*   Updated: 2026/03/25 14:39:15 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coders.h"
#include "codexion.h"
#include "dongle.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	coders_init(t_coders *coders, t_args *args)
{
	int			i;
	t_dongle	*dongle;

	coders->coders = malloc(sizeof(t_coder) * args->number_of_coders);
	if (coders->coders == NULL)
		return (ERR_MALLOC);
	coders->dongles = malloc(sizeof(t_dongle) * args->number_of_coders);
	if (coders->dongles == NULL)
	{
		coders_destroy(coders);
		return (ERR_MALLOC);
	}
	i = -1;
	while (++i < args->number_of_coders)
	{
		coders->coders[i].left_dongle = &coders->dongles[i];
		coders->coders[i].right_dongle = NULL;
		if (args->number_of_coders > 1)
			coders->coders[i].right_dongle = &coders->dongles[ft_mod(i - 1,
					args->number_of_coders)];
	}
	return (0);
}

void	coders_destroy(t_coders *coders)
{
	if (coders->coders != NULL)
		free(coders->coders);
	if (coders->dongles != NULL)
		free(coders->dongles);
	coders->coders = NULL;
	coders->dongles = NULL;
}

void	*coder_routine(void *thread_args)
{
	t_coder	*coder;

	printf("Coder started\n");
	coder = (t_coder *)thread_args;
	printf("TEST %lu\n", coder->tid);
	return (NULL);
}

int	coders_thread_start(t_coders *coders, t_args *args)
{
	int		i;
	int		errcode;
	t_coder	*coder;

	i = -1;
	while (++i < args->number_of_coders)
	{
		coder = &coders->coders[i];
		errcode = pthread_create(&coder->tid, NULL, &coder_routine, coder);
		if (errcode != 0)
			return (ERR_THREAD_CREATE);
	}
	return (0);
}

int	coders_thread_join(t_coders *coders, t_args *args)
{
	int		i;
	int		errcode;
	t_coder	coder;

	i = -1;
	while (++i < args->number_of_coders)
	{
		coder = coders->coders[i];
		errcode = pthread_join(coder.tid, NULL);
		if (errcode != 0)
			return (ERR_THREAD_JOIN);
	}
	return (0);
}

void	debug_coders(t_coders *coders, t_args *args)
{
	int	i;

	if (!coders)
	{
		printf("--- Debug Coders : NULL ---\n");
		return ;
	}
	printf("=== DEBUG ALL CODERS & DONGLES ===\n");
	printf("--- DONGLES ---\n");
	i = 0;
	while (i < args->number_of_coders)
	{
		printf("Dongle [%p] :\n", &coders->dongles[i]);
		printf("  cooldown       : %d\n", coders->dongles[i].cooldown);
		printf("  cooldown_mutex : %p\n",
			(void *)&coders->dongles[i].cooldown_mutex);
		i++;
	}
	printf("--- CODERS ---\n");
	i = 0;
	while (i < args->number_of_coders)
	{
		printf("Coder [%d] :\n", i);
		printf("  tid            : %p\n", (void *)coders->coders[i].tid);
		printf("  left_dongle    : %p\n",
			(void *)coders->coders[i].left_dongle);
		printf("  right_dongle   : %p\n",
			(void *)coders->coders[i].right_dongle);
		i++;
	}
	printf("==================================\n");
}
