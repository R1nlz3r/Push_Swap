/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:05:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/05 19:06:38 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_display_movements(t_push_swap *ps, int mv)
{
	if (mv == SA)
		ft_putendl_fd("sa", ps->fd);
	else if (mv == SB)
		ft_putendl_fd("sb", ps->fd);
	else if (mv == SS)
		ft_putendl_fd("ss", ps->fd);
	else if (mv == PA)
		ft_putendl_fd("pa", ps->fd);
	else if (mv == PB)
		ft_putendl_fd("pb", ps->fd);
	else if (mv == RA)
		ft_putendl_fd("ra", ps->fd);
	else if (mv == RB)
		ft_putendl_fd("rb", ps->fd);
	else if (mv == RR)
		ft_putendl_fd("rr", ps->fd);
	else if (mv == RRA)
		ft_putendl_fd("rra", ps->fd);
	else if (mv == RRB)
		ft_putendl_fd("rrb", ps->fd);
	else if (mv == RRR)
		ft_putendl_fd("rrr", ps->fd);
}

void		push_swap_display_usage(void)
{
	ft_putendl("Usage : ./checker [-l] list of integers");
	ft_putendl("	l : Print rotations in log.txt rather than on stdout");
	exit(-1);
}
