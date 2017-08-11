/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 04:23:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/11 06:41:40 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
if ((ft_tabisdescending(ps->a) || !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len || ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
	push_swap_buffer_movement(ps, PA);
else if ((ft_tabmin(ps->a) <= ps->median / 4 && ps->a->tab[ps->a->len - 1] > ps->median / 4)
	|| (ft_tabmin(ps->a) <= (ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median / 2 && ps->a->tab[ps->a->len - 1] > ps->median / 2)
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median && ps->a->tab[ps->a->len - 1] > ps->median)
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] != ft_tabmin(ps->a)))
	push_swap_buffer_movement(ps, RA);
else if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b) || ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1) && (ps->b->len <= 1
	|| ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b) || ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b)) && ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
	|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1] && (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
	push_swap_buffer_movement(ps, PB);
else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
	|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1])
	|| (ps->a->tab[ps->a->len - 1] > ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
	push_swap_buffer_movement(ps, RRB);
else
	push_swap_buffer_movement(ps, RB);

	500nb -> 6535
*/

/*
if ((ft_tabisdescending(ps->a) || !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len || ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
	push_swap_buffer_movement(ps, PA);
else if ((ft_tabmin(ps->a) <= ps->median / 4 && ft_tabfindrev_undereq(ps->a, ps->median / 4)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 4) <= ft_tabfindrev_undereq(ps->a, ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > ps->median / 4 && ft_tabfindrev_undereq(ps->a, ps->median / 4 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 4 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median / 2 && ft_tabmin(ps->a) > (ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median / 2)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 2) <= ft_tabfindrev_undereq(ps->a, ps->median / 2))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 8) && ft_tabmin(ps->a) > ps->median / 2 && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 2 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4) && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 2 + ps->median / 4) <= ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median / 2 + ps->median / 4 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median)
	&& ft_tabfindpos_undereq(ps->a, ps->median) <= ft_tabfindrev_undereq(ps->a, ps->median))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 8) && ft_tabmin(ps->a) > ps->median && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4) && ft_tabmin(ps->a) > (ps->median + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 4) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 4 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2) && ft_tabmin(ps->a) > (ps->median + ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 2) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 2) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4) && ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8)
	&& ft_tabfindpos_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) <= ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8)))
	push_swap_buffer_movement(ps, RRA);
else if ((ft_tabmin(ps->a) <= ps->median / 4 && ft_tabfindrev_undereq(ps->a, ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > ps->median / 4 && ft_tabfindrev_undereq(ps->a, ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median / 2 && ft_tabmin(ps->a) > (ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median / 2))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 8) && ft_tabmin(ps->a) > ps->median / 2 && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4) && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median / 2 + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= ps->median && ft_tabmin(ps->a) > (ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 8) && ft_tabmin(ps->a) > ps->median && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4) && ft_tabmin(ps->a) > (ps->median + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 4 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2) && ft_tabmin(ps->a) > (ps->median + ps->median / 4 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 2) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 8))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4) && ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 8) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4))
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 4) && ft_tabfindrev_undereq(ps->a, ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8)))
	push_swap_buffer_movement(ps, RA);
else if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b) || ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1) && (ps->b->len <= 1
	|| ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b) || ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b)) && ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
	|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1] && (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
	push_swap_buffer_movement(ps, PB);
else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
	|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1])
	|| (ps->a->tab[ps->a->len - 1] > ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
	push_swap_buffer_movement(ps, RRB);
else
	push_swap_buffer_movement(ps, RB);

	500nb -> 7112
*/

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

static void		push_swap_buffer_movement(t_push_swap *ps, int mv)
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
	else if (ps->lastmove_count && ((ps->lastmove == RRA && mv == RRB)
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

t_push_swap		*push_swap_solver(t_push_swap *ps)
{
	remove("log.txt");
	if (ps->l && (ps->fd = open("log.txt", O_CREAT|O_WRONLY, 0666)) == -1)
		exit (-1);
	ps->median = (int)(ft_tabmedian(ps->a));
	while (!ft_tabisdescending(ps->a) || ps->b->len)
	{
		if ((ft_tabisdescending(ps->a) || !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len || ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
			push_swap_buffer_movement(ps, PA);
		else if ((ft_tabmin(ps->a) <= ps->median / 4 && ps->a->tab[ps->a->len - 1] > ps->median / 4)
			|| (ft_tabmin(ps->a) <= (ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 4 + ps->median / 8))
			|| (ft_tabmin(ps->a) <= ps->median / 2 && ps->a->tab[ps->a->len - 1] > ps->median / 2)
			|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 8))
			|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 4))
			|| (ft_tabmin(ps->a) <= (ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median / 2 + ps->median / 4 + ps->median / 8))
			|| (ft_tabmin(ps->a) <= ps->median && ps->a->tab[ps->a->len - 1] > ps->median)
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 8))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 4))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 4 + ps->median / 8))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 8))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 4))
			|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8))
			|| (ft_tabmin(ps->a) > (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] != ft_tabmin(ps->a)))
			push_swap_buffer_movement(ps, RA);
		else if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b) || ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1) && (ps->b->len <= 1
			|| ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b) || ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b)) && ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
			|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1] && (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
			push_swap_buffer_movement(ps, PB);
		else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
			|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1])
			|| (ps->a->tab[ps->a->len - 1] > ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
			push_swap_buffer_movement(ps, RRB);
		else
			push_swap_buffer_movement(ps, RB);
	}
	push_swap_buffer_movement(ps, 0);
	ft_putstr_fd_buffer("", 1, ps->fd);
	if (ps->l && close(ps->fd))
		exit (-1);
	return (ps);
}
