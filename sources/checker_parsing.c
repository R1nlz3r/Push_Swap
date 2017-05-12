/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:03:31 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/12 18:41:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			checker_parsing_doubles(t_checker *ck)
{
	int		i;
	int		j = 0;
	int		tmp;
	int		zerobool;

	i = 0;
	zerobool = 0;
	while (i < ck->a_size)
	{
		if (!(tmp = ck->a[i]))
			++zerobool;
		if (zerobool > 1 && (ck->error = -1))
			return ;
		j = i++ + 1;
		while (tmp && j < ck->a_size)
		{
			if (tmp == ck->a[j++] && (ck->error = -1))
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
		if ((!argv[ck->argnb][0] || !((ft_isdigit(argv[ck->argnb][0])
			|| argv[ck->argnb][0] == '+' || argv[ck->argnb][0] == '-')
			&& (ft_strisdigit(&argv[ck->argnb][1]) || (!argv[ck->argnb][1]
			&& ft_isdigit(argv[ck->argnb][0]))))
			|| ft_strlen(argv[ck->argnb]) > 11
			|| (ft_strlen(argv[ck->argnb]) == 11
			&& ft_isdigit(argv[ck->argnb][0]))
			|| (ft_strlen(argv[ck->argnb]) == 10
			&& ft_strcmp(argv[ck->argnb], "2147483647") > 0)
			|| (ft_strlen(argv[ck->argnb]) == 11 && argv[ck->argnb][0] == '+'
			&& ft_strcmp(&argv[ck->argnb][1], "2147483647") > 0)
			|| (ft_strlen(argv[ck->argnb]) == 11 && argv[ck->argnb][0] == '-'
			&& ft_strcmp(&argv[ck->argnb][1], "2147483648") > 0))
			&& (ck->error = -1))
			return (ck);
		ck->a[count++] = ft_atoi(argv[ck->argnb]);
		++ck->argnb;
	}
	checker_parsing_doubles(ck);
	return (ck);
}

static t_checker	*checker_parsing_flags2(t_checker *ck, char **argv,
	int *len, int *stmp)
{
	if (argv[ck->argnb][*len] == 'l')
		ck->flags->l = 1;
	else if (argv[ck->argnb][*len] == 'v')
		ck->flags->v = 1;
	else if (argv[ck->argnb][*len] == 'c')
		ck->flags->c = 1;
	else if (argv[ck->argnb][*len] == 's' && (*stmp = 1)
		&& ft_strisdigit(argv[ck->argnb + 1])
		&& ft_strlen(argv[ck->argnb + 1]) <= 6
		&& ft_atoi(argv[ck->argnb + 1]) <= 100000
		&& ft_atoi(argv[ck->argnb + 1]) > 0)
		ck->flags->s = ft_atoi(argv[ck->argnb + 1]);
	else
		ck->error = -1;
	return (ck);
}

t_checker			*checker_parsing_flags(t_checker *ck, int argc, char **argv)
{
	int		len;
	int		stmp;

	while (ck->argnb < argc && argv[ck->argnb][0] == '-')
	{
		stmp = 0;
		if (!(len = (int)ft_strlen(argv[ck->argnb]) - 1) && (ck->error = -1))
			return (ck);
		while (len)
		{
			if (ft_isdigit(argv[ck->argnb][len]))
				return (ck);
			checker_parsing_flags2(ck, argv, &len, &stmp);
			if (ck->error)
				return (ck);
			--len;
		}
		if (stmp)
			++ck->argnb;
		++ck->argnb;
	}
	return (ck);
}
