/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:05:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/11 06:17:49 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_display_movements(t_push_swap *ps, int mv)
{
	if (mv == SA)
		ft_putstr_fd_buffer("sa\n", 0, ps->fd);
	else if (mv == SB)
		ft_putstr_fd_buffer("sb\n", 0, ps->fd);
	else if (mv == SS)
		ft_putstr_fd_buffer("ss\n", 0, ps->fd);
	else if (mv == RA)
		ft_putstr_fd_buffer("ra\n", 0, ps->fd);
	else if (mv == RB)
		ft_putstr_fd_buffer("rb\n", 0, ps->fd);
	else if (mv == RR)
		ft_putstr_fd_buffer("rr\n", 0, ps->fd);
	else if (mv == RRA)
		ft_putstr_fd_buffer("rra\n", 0, ps->fd);
	else if (mv == RRB)
		ft_putstr_fd_buffer("rrb\n", 0, ps->fd);
	else if (mv == RRR)
		ft_putstr_fd_buffer("rrr\n", 0, ps->fd);
	else if (mv == PA)
		ft_putstr_fd_buffer("pa\n", 0, ps->fd);
	else if (mv == PB)
		ft_putstr_fd_buffer("pb\n", 0, ps->fd);
}

void		push_swap_display_usage(void)
{
	ft_putendl("Usage : ./checker [-l] list of integers");
	ft_putendl("	l : Print rotations in log.txt rather than on stdout");
	exit(-1);
}
