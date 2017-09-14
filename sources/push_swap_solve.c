/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 04:23:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/14 17:20:12 by mapandel         ###   ########.fr       */
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

static void		push_swap_init_percentiles(t_push_swap *ps)
{
	ps->q12 = (int)(ft_tabpercentile(ps->a, 12));
	ps->q19 = (int)(ft_tabpercentile(ps->a, 19));
	ps->q25 = (int)(ft_tabpercentile(ps->a, 25));
	ps->q32 = (int)(ft_tabpercentile(ps->a, 32));
	ps->q37 = (int)(ft_tabpercentile(ps->a, 37));
	ps->q44 = (int)(ft_tabpercentile(ps->a, 44));
	ps->median = (int)(ft_tabmedian(ps->a));
	ps->q57 = (int)(ft_tabpercentile(ps->a, 57));
	ps->q62 = (int)(ft_tabpercentile(ps->a, 62));
	ps->q69 = (int)(ft_tabpercentile(ps->a, 69));
	ps->q75 = (int)(ft_tabpercentile(ps->a, 75));
	ps->q82 = (int)(ft_tabpercentile(ps->a, 82));
	ps->q87 = (int)(ft_tabpercentile(ps->a, 87));
	ps->q94 = (int)(ft_tabpercentile(ps->a, 94));
}

t_push_swap		*push_swap_solver(t_push_swap *ps)
{
	remove("log.txt");
	if (ps->l && (ps->fd = open("log.txt", O_CREAT | O_WRONLY, 0666)) == -1)
		push_swap_display_error();
	push_swap_init_percentiles(ps);
	while (!ft_tabisdescending(ps->a) || ps->b->len)
	{
		if (((ps->a->len == 3
			&& ((ft_tabmin(ps->a) == ps->a->tab[0]
			&& ft_tabmax(ps->a) == ps->a->tab[1])
			|| (ft_tabmin(ps->a) == ps->a->tab[0]
			&& ft_tabmax(ps->a) == ps->a->tab[2]))) || ps->a->len == 2)
			&& !ft_tabisdescending(ps->a))
			push_swap_buffer_movement(ps, RRA);
		else
			push_swap_solver2(ps);
	}
	push_swap_buffer_movement(ps, 0);
	ft_putstr_fd_buffer("", 1, ps->fd);
	if (ps->l && close(ps->fd))
		push_swap_display_error();
	return (ps);
}
