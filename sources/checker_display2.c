/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_display2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:18:44 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/06 04:25:12 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		checker_display_nbrotations(t_checker *ck)
{
	ft_putstr("\033c");
	ft_putstr("\033[4mThe number of rotations\033[24m : ");
	ft_putnbr(ck->nbrotations);
	ft_putchar('\n');
}

static void		checker_display_rotation(t_checker *ck)
{
	ft_putstr("\033[4mLast rotation\033[24m : ");
	if (ck->rotation == SA)
		ft_putstr("sa");
	else if (ck->rotation == SB)
		ft_putstr("sb");
	else if (ck->rotation == SS)
		ft_putstr("ss");
	else if (ck->rotation == PA)
		ft_putstr("pa");
	else if (ck->rotation == PB)
		ft_putstr("pb");
	else if (ck->rotation == RA)
		ft_putstr("ra");
	else if (ck->rotation == RB)
		ft_putstr("rb");
	else if (ck->rotation == RR)
		ft_putstr("rr");
	else if (ck->rotation == RRA)
		ft_putstr("rra");
	else if (ck->rotation == RRB)
		ft_putstr("rrb");
	else if (ck->rotation == RRR)
		ft_putstr("rrr");
	ft_putchar('\n');
}

static void		checker_display_stacks(t_checker *ck)
{
	size_t		i;

	i = 0;
	ft_putendl("\n\033[4mStacks\033[24m :");
	ft_putendl("/*");
	ft_putstr("** \033[7ma\033[27m");
	while (i < ck->a->len)
	{
		ft_putstr(" ");
		ft_putnbr(ck->a->tab[i]);
		++i;
	}
	ft_putchar('\n');
	ft_putstr("** \033[7mb\033[27m");
	i = 0;
	while (i < ck->b->len)
	{
		ft_putstr(" ");
		ft_putnbr(ck->b->tab[i]);
		++i;
	}
	ft_putchar('\n');
	ft_putendl("*/\n");
}

void			checker_display_v_flag(t_checker *ck)
{
	checker_display_nbrotations(ck);
	checker_display_rotation(ck);
	checker_display_stacks(ck);
}
