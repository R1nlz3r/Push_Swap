/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:55:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/06 16:09:39 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checker_display(int result)
{
	if (result == OK)
	{
		ft_putendl("OK");
		return (0);
	}
	if (result == KO)
		ft_putendl("KO");
	else if (result == ERROR)
		ft_putendl("Error");
	return (-1);
}
