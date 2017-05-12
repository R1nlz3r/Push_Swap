/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:55:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/12 17:37:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		checker_display_start(void)
{
	ft_putstr("\033c");
	ft_putendl("\033[90m\033[1m**************************************");
	ft_putendl("**\033[0m          42 - Push_swap          \033[90m\033[1m**");
	ft_putendl("**************************************\033[0m\n");
}

int		checker_display_usage(void)
{
	ft_putendl("Usage : ./checker [-clsv] list of integers");
	ft_putendl("	l : Get rotations from log.txt");
	ft_putendl("	s + [0 < speedtime < 100000] : Choose speedtime \
(microseconds)");
	ft_putendl("	v : Print the stacks + number of rotations + last move");
	ft_putendl("	c (+ v) : Colorise the last move");
	return (checker_display_result(ERROR));
}

int			checker_display_result(int result)
{
	if (result == OK)
	{
		ft_putendl("\033[32mOK");
		return (0);
	}
	if (result == KO)
		ft_putendl("\033[31mKO");
	else if (result == ERROR)
		ft_putendl("\033[31mError\033[0m");
	return (-1);
}
