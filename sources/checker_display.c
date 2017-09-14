/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:55:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/14 18:42:37 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checker_display_usage(void)
{
	ft_putstr_buffer("Usage : ./checker [-lsv] list of integers\n", 1);
	ft_putstr_buffer("	l : Get rotations from log.txt\n", 1);
	ft_putstr_buffer("	v : Print the stacks + number of rotations", 1);
	ft_putstr_buffer(" + last move\n", 1);
	ft_putstr_buffer("	s + [0 < delay < 5000000] :", 1);
	ft_putstr_buffer(" Choose delay (microseconds) with -v triggered\n", 1);
	return (0);
}

int		checker_display_result(int result)
{
	if (result == OK)
	{
		ft_putendl("\033[32mOK\033[0m");
		return (0);
	}
	if (result == KO)
		ft_putendl("\033[31mKO\033[0m");
	else if (result == ERROR)
		ft_putendl_fd("\033[31mError\033[0m", 2);
	return (-1);
}
