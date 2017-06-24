/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 04:23:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/24 06:19:14 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
if (ps->a->len >= 2 && ps->b->len >= 2
	&& ps->a->tab[ps->a->len - 2] < ps->a->tab[ps->a->len - 1]
	&& ps->b->tab[ps->b->len - 2] > ps->b->tab[ps->b->len - 1])
	push_swap_display_movements(ps, SS);
else if (ps->b->len >= 2
	&& ps->b->tab[ps->b->len - 2] > ps->b->tab[ps->b->len - 1])
	push_swap_display_movements(ps, SB);
else if (ft_tabisdescending(ps->a) && ps->b->tab[ps->b->len - 1]
	< ps->a->tab[ps->a->len - 1])
	push_swap_display_movements(ps, PA);
else if ((ft_tabmin(ps->a) == ps->a->tab[ps->a->len - 1])
	|| (ft_tabmin_overone(ps->a) == ps->a->tab[ps->a->len - 1]))
	push_swap_display_movements(ps, PB);
else if ((ft_tabminpos(ps->a) < ps->a->len / 2
	|| ft_tabminpos_overone(ps->a) < ps->a->len / 2))
	push_swap_display_movements(ps, RRA);
else
	push_swap_display_movements(ps, RA);

	500nb -> 27289
*/

/*
if ((ft_tabisdescending(ps->a) || !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len || ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
	push_swap_display_movements(ps, PA);
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
	|| (ft_tabmin(ps->a) <= (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8) && ps->a->tab[ps->a->len - 1] > (ps->median + ps->median / 2 + ps->median / 4 + ps->median / 8)))
	push_swap_display_movements(ps, RA);
else if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b) || ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1) && (ps->b->len <= 1
	|| ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b) || ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b)) && ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
	|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1] && (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
	push_swap_display_movements(ps, PB);
else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
	|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1])
	|| (ps->a->tab[ps->a->len - 1] > ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
	push_swap_display_movements(ps, RRB);
else
	push_swap_display_movements(ps, RB);

	500nb -> 7273
*/

/*
if ((ft_tabisdescending(ps->a) || !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len || ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
	push_swap_display_movements(ps, PA);
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
	push_swap_display_movements(ps, RRA);
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
	push_swap_display_movements(ps, RA);
else if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b) || ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1) && (ps->b->len <= 1
	|| ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b) || ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b)) && ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
	|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1] && (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
	push_swap_display_movements(ps, PB);
else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
	|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1])
	|| (ps->a->tab[ps->a->len - 1] > ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2 && ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
	push_swap_display_movements(ps, RRB);
else
	push_swap_display_movements(ps, RB);

	500nb -> 7776
*/

t_push_swap		*push_swap_solver(t_push_swap *ps)
{
	remove("log.txt");
	if (ps->l && (ps->fd = open("log.txt", O_CREAT|O_WRONLY, 0666)) == -1)
		exit (-1);
	ps->median = (int)(ft_tabmedian(ps->a));
	while (!ft_tabisdescending(ps->a) || ps->b->len)
	{
		//Choose your algorithm
	}
	if (ps->l && close(ps->fd))
		exit (-1);
	return (ps);
}
