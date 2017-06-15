/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:00:23 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/06 18:51:47 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_swap_parsing_doubles(t_push_swap *ps)
{
	size_t		i;
	size_t		j;
	int			tmp;
	int			zerobool;

	i = 0;
	zerobool = 0;
	while (i < ps->a->len)
	{
		if (!(tmp = ps->a->tab[i]))
			++zerobool;
		if (zerobool > 1)
			exit(-1);
		j = i++ + 1;
		while (tmp && j < ps->a->len)
		{
			if (tmp == ps->a->tab[j++])
				exit(-1);
		}
	}
}

t_push_swap			*push_swap_parsing_integers(t_push_swap *ps,
	int argc, char **argv)
{
	int		count;

	count = 0;
	while (ps->argnb < argc)
	{
		if (!argv[ps->argnb][0] || !((ft_isdigit(argv[ps->argnb][0])
			|| argv[ps->argnb][0] == '+' || argv[ps->argnb][0] == '-')
			&& (ft_strisdigit(&argv[ps->argnb][1]) || (!argv[ps->argnb][1]
			&& ft_isdigit(argv[ps->argnb][0]))))
			|| ft_strlen(argv[ps->argnb]) > 11
			|| (ft_strlen(argv[ps->argnb]) == 11
			&& ft_isdigit(argv[ps->argnb][0]))
			|| (ft_strlen(argv[ps->argnb]) == 10
			&& ft_strcmp(argv[ps->argnb], "2147483647") > 0)
			|| (ft_strlen(argv[ps->argnb]) == 11 && argv[ps->argnb][0] == '+'
			&& ft_strcmp(&argv[ps->argnb][1], "2147483647") > 0)
			|| (ft_strlen(argv[ps->argnb]) == 11 && argv[ps->argnb][0] == '-'
			&& ft_strcmp(&argv[ps->argnb][1], "2147483648") > 0))
			exit(-1);
		ps->a->tab[count++] = ft_atoi(argv[ps->argnb]);
		++ps->argnb;
	}
	push_swap_parsing_doubles(ps);
	ps->a = ft_tabrev_leakless(ps->a);
	return (ps);
}

t_push_swap			*push_swap_parsing_flags(t_push_swap *ps, int argc,
	char **argv)
{
	int		len;

	while (ps->argnb < argc && argv[ps->argnb][0] == '-')
	{
		if (!(len = (int)ft_strlen(argv[ps->argnb]) - 1))
			exit(-1);
		while (len)
		{
			if (ft_isdigit(argv[ps->argnb][len]))
				return (ps);
			if (argv[ps->argnb][len] == 'l')
				ps->l = 1;
			else
				exit(-1);
			--len;
		}
		++ps->argnb;
	}
	return (ps);
}
