/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:00:23 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/16 17:16:22 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_swap_parsing_doubles(t_push_swap *ps)
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
			push_swap_display_error();
		j = i++ + 1;
		while (tmp && j < ps->a->len)
		{
			if (tmp == ps->a->tab[j++])
				push_swap_display_error();
		}
	}
}

t_push_swap		*push_swap_parsing_integers(t_push_swap *ps,
	int argc, char **argv)
{
	int		count;

	count = 0;
	while (ps->argnb < argc)
	{
		if (ft_atoi_strict(argv[ps->argnb]) == 10000000000)
			push_swap_display_error();
		ps->a->tab[count++] = ft_atoi(argv[ps->argnb++]);
	}
	return (ps);
}

t_push_swap		*push_swap_parsing_bash_arg(t_push_swap *ps, char **argv)
{
	char	**split;
	int		i;

	split = ft_strsplit(argv[ps->argnb], ' ');
	i = 0;
	while (split[i])
	{
		if (ft_atoi_strict(split[i]) == 10000000000)
			push_swap_display_error();
		ps->a->tab[i] = ft_atoi(split[i]);
		ft_strdel(&split[i++]);
	}
	if (!(ps->a->len = (size_t)i))
		push_swap_display_error();
	ft_memdel((void**)&split);
	return (ps);
}

t_push_swap		*push_swap_parsing_flags(t_push_swap *ps, int argc,
	char **argv)
{
	int		len;

	while (ps->argnb < argc && argv[ps->argnb][0] == '-')
	{
		if (!(len = (int)ft_strlen(argv[ps->argnb]) - 1))
			push_swap_display_error();
		while (len)
		{
			if (ft_isdigit(argv[ps->argnb][len]))
				return (ps);
			if (argv[ps->argnb][len] == 'l')
				ps->l = 1;
			else
				push_swap_display_error();
			--len;
		}
		++ps->argnb;
	}
	return (ps);
}
