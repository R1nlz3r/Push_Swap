/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 04:23:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/29 06:08:32 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_swap_movements(t_push_swap *ps, int mv)
{
	if (mv == SA)
		ft_tabswap(ps->a);
	else if (mv == SB)
		ft_tabswap(ps->b);
	else if (mv == RA)
		ft_tabrotate(ps->a);
	else if (mv == RB)
		ft_tabrotate(ps->b);
	else if (mv == RRA)
		ft_tabrevrotate(ps->a);
	else if (mv == RRB)
		ft_tabrevrotate(ps->b);
	else if (mv == PA)
		ft_tabpush(ps->b, ps->a);
	else if (mv == PB)
		ft_tabpush(ps->a, ps->b);
}

static void		push_swap_buffer_movement2(t_push_swap *ps, int mv)
{
	if (ps->lastmove_count && ((ps->lastmove == RRA && mv == RRB)
		|| (ps->lastmove == RRB && mv == RRA)))
	{
		--ps->lastmove_count;
		push_swap_display_movements(ps, RRR);
	}
	else if (mv != ps->lastmove)
	{
		while (ps->lastmove_count)
		{
			--ps->lastmove_count;
			push_swap_display_movements(ps, ps->lastmove);
		}
		++ps->lastmove_count;
		ps->lastmove = mv;
	}
}

void			push_swap_buffer_movement(t_push_swap *ps, int mv)
{
	push_swap_movements(ps, mv);
	if (!ps->lastmove_count)
		ps->lastmove = mv;
	if (!ps->lastmove_count)
		++ps->lastmove_count;
	else if (ps->lastmove == mv)
		++ps->lastmove_count;
	else if (ps->lastmove_count && ((ps->lastmove == SA && mv == SB)
		|| (ps->lastmove == SB && mv == SA)))
	{
		--ps->lastmove_count;
		push_swap_display_movements(ps, SS);
	}
	else if (ps->lastmove_count && ((ps->lastmove == RA && mv == RB)
		|| (ps->lastmove == RB && mv == RA)))
	{
		--ps->lastmove_count;
		push_swap_display_movements(ps, RR);
	}
	else
		push_swap_buffer_movement2(ps, mv);
}

t_push_swap		*push_swap_solver(t_push_swap *ps)
{
	remove("log.txt");
	if (ps->l && (ps->fd = open("log.txt", O_CREAT | O_WRONLY, 0666)) == -1)
		exit(-1);
	ps->median = (int)(ft_tabmedian(ps->a));
	while (!ft_tabisdescending(ps->a) || ps->b->len)
	{
		if (!ps->b->len && ((ps->a->len == 3
			&& ((ft_tabmin(ps->a) == ps->a->tab[0]
			&& ft_tabmax(ps->a) == ps->a->tab[1])
			|| (ft_tabmin(ps->a) == ps->a->tab[0]
			&& ft_tabmax(ps->a) == ps->a->tab[2]))) || ps->a->len == 2))
			push_swap_buffer_movement(ps, RRA);
		else
			push_swap_solver2(ps);
	}
	push_swap_buffer_movement(ps, 0);
	ft_putstr_fd_buffer("", 1, ps->fd);
	if (ps->l && close(ps->fd))
		exit(-1);
	return (ps);
}
