/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 05:38:22 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/18 10:14:59 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_checker	*checker_parsing_movements2(t_checker *ck)
{
	if (!ft_strncmp(ck->line, "rrb", 3) && ft_strlen(ck->line) == 3
		&& (ck->rotation = RRB))
		ft_tabrevrotate(ck->b);
	else if (!ft_strncmp(ck->line, "rrr", 3) && ft_strlen(ck->line) == 3
		&& ft_tabrevrotate(ck->a) && (ck->rotation = RRR))
		ft_tabrevrotate(ck->b);
	else if (!ft_strncmp(ck->line, "ra", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = RA))
		ft_tabrotate(ck->a);
	else if (!ft_strncmp(ck->line, "rb", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = RB))
		ft_tabrotate(ck->b);
	else if (!ft_strncmp(ck->line, "rr", 2) && ft_strlen(ck->line) == 2
		&& ft_tabrotate(ck->a) && (ck->rotation = RR))
		ft_tabrotate(ck->b);
	else
		ck->error = 1;
	return (ck);
}

t_checker			*checker_parsing_movements(t_checker *ck)
{
	if (!ft_strncmp(ck->line, "sa", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = SA))
		ft_tabswap(ck->a);
	else if (!ft_strncmp(ck->line, "sb", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = SB))
		ft_tabswap(ck->b);
	else if (!ft_strncmp(ck->line, "ss", 2) && ft_strlen(ck->line) == 2
		&& ft_tabswap(ck->a) && (ck->rotation = SS))
		ft_tabswap(ck->b);
	else if (!ft_strncmp(ck->line, "pa", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = PA))
		ft_tabpush(ck->b, ck->a);
	else if (!ft_strncmp(ck->line, "pb", 2) && ft_strlen(ck->line) == 2
		&& (ck->rotation = PB))
		ft_tabpush(ck->a, ck->b);
	else if (!ft_strncmp(ck->line, "rra", 3) && ft_strlen(ck->line) == 3
		&& (ck->rotation = RRA))
		ft_tabrevrotate(ck->a);
	else
		return (checker_parsing_movements2(ck));
	return (ck);
}

void				checker_parsing_doubles(t_checker *ck)
{
	size_t		i;
	size_t		j;
	int			tmp;
	int			zerobool;

	i = 0;
	zerobool = 0;
	while (i < ck->a->len)
	{
		if (!(tmp = ck->a->tab[i]))
			++zerobool;
		if (zerobool > 1 && (ck->error = -1))
			return ;
		j = i++ + 1;
		while (tmp && j < ck->a->len)
		{
			if (tmp == ck->a->tab[j++] && (ck->error = -1))
				return ;
		}
	}
}

t_checker			*checker_parsing_integers(t_checker *ck, int argc,
	char **argv)
{
	int		count;

	count = 0;
	while (ck->argnb < argc)
	{
		if (ft_atoi_strict(argv[ck->argnb]) == 10000000000 && (ck->error = -1))
			return (ck);
		ck->a->tab[count++] = ft_atoi(argv[ck->argnb]);
		++ck->argnb;
	}
	return (ck);
}
