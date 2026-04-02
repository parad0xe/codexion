/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:06:15 by nlallema          #+#    #+#             */
/*   Updated: 2026/04/02 22:28:42 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

# include "codexion.h"

void		exception_sys(t_errcode errcode);
void		exception_args(t_errcode errcode);
void		exception_dongle(t_errcode errcode);
void		exception_coder(t_errcode errcode);
void		exception_workspace(t_errcode errcode);
void		exception_sim(t_errcode errcode);
void		exception_heapq(t_errcode errcode);

t_errcode	exception(t_errcode errcode);

#endif
