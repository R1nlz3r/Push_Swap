/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_display2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:18:44 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/07 12:33:02 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		checker_display_nbrotations(t_checker *ck)
{
	//\033[?25l Hide Cursor
	ft_putstr_buffer("\033[H\033[J", 0);
	ft_putstr_buffer("\033[4mThe number of rotations\033[24m : ", 0);
	ft_putllnbr_buffer(ck->nbrotations, 0);
	ft_putchar_buffer('\n', 0);
}

static void		checker_display_rotation(t_checker *ck)
{
	ft_putstr_buffer("\033[4mLast rotation\033[24m : ", 0);
	if (ck->rotation == SA)
		ft_putstr_buffer("sa", 0);
	else if (ck->rotation == SB)
		ft_putstr_buffer("sb", 0);
	else if (ck->rotation == SS)
		ft_putstr_buffer("ss", 0);
	else if (ck->rotation == PA)
		ft_putstr_buffer("pa", 0);
	else if (ck->rotation == PB)
		ft_putstr_buffer("pb", 0);
	else if (ck->rotation == RA)
		ft_putstr_buffer("ra", 0);
	else if (ck->rotation == RB)
		ft_putstr_buffer("rb", 0);
	else if (ck->rotation == RR)
		ft_putstr_buffer("rr", 0);
	else if (ck->rotation == RRA)
		ft_putstr_buffer("rra", 0);
	else if (ck->rotation == RRB)
		ft_putstr_buffer("rrb", 0);
	else if (ck->rotation == RRR)
		ft_putstr_buffer("rrr", 0);
	ft_putchar_buffer('\n', 0);
}

static void		checker_display_stacks(t_checker *ck)
{
	size_t		i;

	i = 0;
	ft_putstr_buffer("\n\033[4mStacks\033[24m :\n", 0);
	ft_putstr_buffer("/*\n", 0);
	ft_putstr_buffer("** \033[7ma\033[27m", 0);
	while (i < ck->a->len)
	{
		ft_putstr_buffer(" ", 0);
		ft_putllnbr_buffer(ck->a->tab[i], 0);
		++i;
	}
	ft_putchar_buffer('\n', 0);
	ft_putstr_buffer("** \033[7mb\033[27m", 0);
	i = 0;
	while (i < ck->b->len)
	{
		ft_putstr_buffer(" ", 0);
		ft_putllnbr_buffer(ck->b->tab[i], 0);
		++i;
	}
	ft_putchar_buffer('\n', 0);
	ft_putendl_buffer("*/\n", 1);
}

void			checker_display_v_flag(t_checker *ck)
{
	checker_display_nbrotations(ck);
	checker_display_rotation(ck);
	checker_display_stacks(ck);
}
