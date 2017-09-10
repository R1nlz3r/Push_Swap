/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:31:16 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 15:02:28 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_checker		*checker_movements(t_checker *ck)
{
	if (ck->flags->l && (((ck->fd = open("log.txt", O_RDONLY)) < 0)
		|| read(ck->fd, 0, 0)) && (ck->error = -1))
		return (ck);
	if (ck->flags->v)
		checker_display_v_flag(ck);
	while (get_next_line(ck->fd, &ck->line) > 0)
	{
		if (ck->flags->v)
			usleep((useconds_t)ck->flags->s);
		ck = checker_parsing_movements(ck);
		if (ck->error || !ck->line[0])
		{
			ft_strdel(&ck->line);
			break ;
		}
		if (ck->flags->v && ++ck->nbrotations)
			checker_display_v_flag(ck);
		ft_strdel(&ck->line);
	}
	ft_strdel(&ck->line);
	if (ck->flags->l && close(ck->fd) == -1)
		ck->error = 1;
	if (!ck->error && (!ft_tabisdescending(ck->a) || ck->b->len))
		ck->error = -1;
	return (ck);
}
