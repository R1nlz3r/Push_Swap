/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:03:31 by mapandel          #+#    #+#             */
/*   Updated: 2017/08/29 06:51:41 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			checker_parsing_bash_arg2(t_checker *ck, int i,
	char **split)
{
	if (!(ck->a->len = (size_t)i))
		exit(-1);
	ft_memdel((void**)&split);
}

t_checker			*checker_parsing_bash_arg(t_checker *ck, char **argv)
{
	char	**split;
	int		i;

	split = ft_strsplit(argv[ck->argnb], ' ');
	i = 0;
	while (split[i])
	{
		if ((!split[i][0] || !((ft_isdigit(split[i][0]) || split[i][0] == '+'
			|| split[i][0] == '-') && (ft_strisdigit(&split[i][1])
			|| (!split[i][1] && ft_isdigit(split[i][0]))))
			|| ft_strlen(split[i]) > 11
			|| (ft_strlen(split[i]) == 11 && ft_isdigit(split[i][0]))
			|| (ft_strlen(split[i]) == 10
			&& ft_strcmp(split[i], "2147483647") > 0)
			|| (ft_strlen(split[i]) == 11 && split[i][0] == '+'
			&& ft_strcmp(&split[i][1], "2147483647") > 0)
			|| (ft_strlen(split[i]) == 11 && split[i][0] == '-'
			&& ft_strcmp(&split[i][1], "2147483648") > 0))
			&& (ck->error = -1))
			return (ck);
		ck->a->tab[i] = ft_atoi(split[i]);
		ft_strdel(&split[i++]);
	}
	checker_parsing_bash_arg2(ck, i, split);
	return (ck);
}

static t_checker	*checker_parsing_flags2(t_checker *ck, char **argv,
	int *len, int *stmp)
{
	if (argv[ck->argnb][*len] == 'l')
		ck->flags->l = 1;
	else if (argv[ck->argnb][*len] == 'v')
		ck->flags->v = 1;
	else if (argv[ck->argnb][*len] == 's' && (*stmp = 1)
		&& ft_strisdigit(argv[ck->argnb + 1])
		&& ft_strlen(argv[ck->argnb + 1]) <= 7
		&& ft_atoi(argv[ck->argnb + 1]) <= 5000000
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
		if (!(len = (int)ft_strlen(argv[ck->argnb]) - 1)
			&& (ck->error = -1))
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
