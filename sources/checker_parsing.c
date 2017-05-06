/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:03:31 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/06 19:55:34 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		checker_parsing_doubles(t_checker *ck)
{
	size_t	i;
	size_t	j = 0;
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

t_checker		*checker_parsing(t_checker *ck, char **argv)
{
	size_t		arg;

	arg = 1;
	while (arg < ck->a_size + 1)
	{
		if ((!argv[arg][0] || !((ft_isdigit(argv[arg][0]) || argv[arg][0] == '+'
			|| argv[arg][0] == '-') && (ft_strisdigit(&argv[arg][1])
			|| (!argv[arg][1] && ft_isdigit(argv[arg][0]))))
			|| ft_strlen(argv[arg]) > 11 || (ft_strlen(argv[arg]) == 11
			&& ft_isdigit(argv[arg][0])) || (ft_strlen(argv[arg]) == 10
			&& ft_strcmp(argv[arg], "2147483647") > 0)
			|| (ft_strlen(argv[arg]) == 11 && argv[arg][0] == '+'
			&& ft_strcmp(&argv[arg][1], "2147483647") > 0)
			|| (ft_strlen(argv[arg]) == 11 && argv[arg][0] == '-'
			&& ft_strcmp(&argv[arg][1], "2147483648") > 0)) && (ck->error = -1))
			return (ck);
		ck->a[arg - 1] = ft_atoi(argv[arg]);
		++arg;
	}
	checker_parsing_doubles(ck);
	if (ck->error)
		return (ck);
	return (ck);
}
