/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:46:22 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/09 13:41:42 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_swap_solver6(t_push_swap *ps)
{
	if (ps->a->len && ((ft_tabmax(ps->a) > ft_tabmin(ps->b)
		|| ft_tabmin(ps->a) < ft_tabmax(ps->b)) || ps->b->len <= 1)
		&& (ps->b->len <= 1 || ((ps->a->tab[ps->a->len - 1] < ft_tabmin(ps->b)
		|| ps->a->tab[ps->a->len - 1] > ft_tabmax(ps->b))
		&& ps->b->tab[ps->b->len - 1] == ft_tabmax(ps->b))
		|| (ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]
		&& (!ps->b->len || ps->a->tab[ps->a->len - 1] < ps->b->tab[0]))))
		push_swap_buffer_movement(ps, PB);
	else if ((!ps->a->len && ft_tabmaxpos(ps->b) < ps->b->len / 2)
		|| (ps->a->tab[ps->a->len - 1] < ft_tabmedian(ps->b)
		&& ft_tabmaxpos(ps->b) >= ps->b->len / 2 && ps->a->tab[ps->a->len - 1]
		> ps->b->tab[ps->b->len - 1]) || (ps->a->tab[ps->a->len - 1]
		> ft_tabmedian(ps->b) && ft_tabmaxpos(ps->b) < ps->b->len / 2
		&& ps->a->tab[ps->a->len - 1] > ps->b->tab[0]))
		push_swap_buffer_movement(ps, RRB);
	else
		push_swap_buffer_movement(ps, RB);
}

static void		push_swap_solver5(t_push_swap *ps)
{
	if (ps->a->len > 100
		&& ((ft_tabmin(ps->a) <= ps->q75
		&& ps->a->tab[ps->a->len - 1] > ps->q75)
		|| (ft_tabmin(ps->a) <= ps->q82 && ps->a->tab[ps->a->len - 1] > ps->q82)
		|| (ft_tabmin(ps->a) <= ps->q87 && ps->a->tab[ps->a->len - 1] > ps->q87)
		|| (ft_tabmin(ps->a) <= ps->q94 && ps->a->tab[ps->a->len - 1] > ps->q94)
		|| (ft_tabmin(ps->a) > ps->q94
		&& ps->a->tab[ps->a->len - 1] != ft_tabmin(ps->a))))
		push_swap_buffer_movement(ps, RA);
	else
		push_swap_solver6(ps);
}

static void		push_swap_solver4(t_push_swap *ps)
{
	if (ps->a->len > 100
		&& ((ft_tabmin(ps->a) <= ps->q12
		&& ps->a->tab[ps->a->len - 1] > ps->q12)
		|| (ft_tabmin(ps->a) <= ps->q19 && ps->a->tab[ps->a->len - 1] > ps->q19)
		|| (ft_tabmin(ps->a) <= ps->q25 && ps->a->tab[ps->a->len - 1] > ps->q25)
		|| (ft_tabmin(ps->a) <= ps->q32 && ps->a->tab[ps->a->len - 1] > ps->q32)
		|| (ft_tabmin(ps->a) <= ps->q37 && ps->a->tab[ps->a->len - 1] > ps->q37)
		|| (ft_tabmin(ps->a) <= ps->q44 && ps->a->tab[ps->a->len - 1] > ps->q44)
		|| (ft_tabmin(ps->a) <= ps->median
		&& ps->a->tab[ps->a->len - 1] > ps->median)
		|| (ft_tabmin(ps->a) <= ps->q57 && ps->a->tab[ps->a->len - 1] > ps->q57)
		|| (ft_tabmin(ps->a) <= ps->q62 && ps->a->tab[ps->a->len - 1] > ps->q62)
		|| (ft_tabmin(ps->a) <= ps->q69
		&& ps->a->tab[ps->a->len - 1] > ps->q69)))
		push_swap_buffer_movement(ps, RA);
	else
		push_swap_solver5(ps);
}

static void		push_swap_solver3(t_push_swap *ps)
{
	if (ps->a->len <= 100
		&& ((ft_tabmin(ps->a) <= ps->q12
		&& ps->a->tab[ps->a->len - 1] > ps->q12)
		|| (ft_tabmin(ps->a) <= ps->q19 && ps->a->tab[ps->a->len - 1] > ps->q19)
		|| (ft_tabmin(ps->a) <= ps->q25 && ps->a->tab[ps->a->len - 1] > ps->q25)
		|| (ft_tabmin(ps->a) <= ps->q32 && ps->a->tab[ps->a->len - 1] > ps->q32)
		|| (ft_tabmin(ps->a) <= ps->q37 && ps->a->tab[ps->a->len - 1] > ps->q37)
		|| (ft_tabmin(ps->a) <= ps->median
		&& ps->a->tab[ps->a->len - 1] > ps->median)
		|| (ft_tabmin(ps->a) <= ps->q62 && ps->a->tab[ps->a->len - 1] > ps->q62)
		|| (ft_tabmin(ps->a) <= ps->q75 && ps->a->tab[ps->a->len - 1] > ps->q75)
		|| (ft_tabmin(ps->a) <= ps->q87 && ps->a->tab[ps->a->len - 1] > ps->q87)
		|| (ft_tabmin(ps->a) <= ps->q94 && ps->a->tab[ps->a->len - 1] > ps->q94)
		|| (ft_tabmin(ps->a) > ps->q94
		&& ps->a->tab[ps->a->len - 1] != ft_tabmin(ps->a))))
		push_swap_buffer_movement(ps, RA);
	else
		push_swap_solver4(ps);
}

void			push_swap_solver2(t_push_swap *ps)
{
	if (!ps->b->len && ps->a->len == 3
		&& ps->a->tab[ps->a->len - 1] < ps->a->tab[ps->a->len - 2])
		push_swap_buffer_movement(ps, SA);
	else if (!ps->b->len && ps->a->len <= 3)
		push_swap_buffer_movement(ps, RA);
	else if (ft_tabisincreasing(ps->a) && !ps->b->len)
	{
		while (ps->a->len > 1)
		{
			push_swap_buffer_movement(ps, RRA);
			push_swap_buffer_movement(ps, PB);
		}
	}
	else if ((ft_tabisdescending(ps->a)
		|| !ps->a->len) && ft_tabisincreasing(ps->b) && (!ps->a->len
		|| ps->a->tab[ps->a->len - 1] > ps->b->tab[ps->b->len - 1]))
		push_swap_buffer_movement(ps, PA);
	else if (ps->a->len <= 5 && ((ft_tabmin(ps->a) <= ps->median
		&& ps->a->tab[ps->a->len - 1] > ps->median)
		|| (ft_tabmin(ps->a) > ps->median
		&& ps->a->tab[ps->a->len - 1] != ft_tabmin(ps->a))))
		push_swap_buffer_movement(ps, RA);
	else
		push_swap_solver3(ps);
}
