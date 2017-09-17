/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:03:31 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/17 09:33:11 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_checker			*checker_parsing_bash_arg(t_checker *ck, char **argv)
{
	char	**split;
	int		i;

	split = ft_strsplit(argv[ck->argnb], ' ');
	i = 0;
	while (split[i])
	{
		if (ft_atoi_strict(split[i]) == 10000000000 && (ck->error = -1))
			return (ck);
		ck->a->tab[i] = ft_atoi(split[i]);
		ft_strdel(&split[i++]);
	}
	ft_memdel((void**)&split);
	if (!(ck->a->len = (size_t)i))
	{
		checker_display_result(ERROR);
		exit(-1);
	}
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
		&& ft_atoi_strict(argv[ck->argnb + 1]) <= 5000000
		&& ft_atoi_strict(argv[ck->argnb + 1]) > 0)
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
