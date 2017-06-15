/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 04:23:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/14 07:10:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap		*push_swap_solver(t_push_swap *ps)
{
	remove("log.txt");
	if (ps->l && (ps->fd = open("log.txt", O_CREAT|O_WRONLY, 0666)) == -1)
		exit (-1);
	ps->median = (int)(ft_tabmedian(ps->a));
	while (!ft_tabisdescending(ps->a) || ps->b->len)
	{
		if (ft_tabisdescending(ps->a) && ps->b->tab[ps->b->len - 1]
			< ps->a->tab[ps->a->len - 1])
		{
			ft_tabpush(ps->b, ps->a);
			push_swap_display_movements(ps, PA);
		}
		else if (ft_tabmin(ps->a) == ps->a->tab[ps->a->len - 1])
		{
			ft_tabpush(ps->a, ps->b);
			push_swap_display_movements(ps, PB);
		}
		else if ((ps->a = ft_tabrotate(ps->a)))
			push_swap_display_movements(ps, RA);
	}
	if (ps->l && close(ps->fd))
		exit (-1);
	return (ps);
}
