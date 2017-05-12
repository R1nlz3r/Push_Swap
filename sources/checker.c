/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/12 18:47:50 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			del_t_checker(t_checker *ck)
{
	ft_tabdel(&ck->a);
	ft_tabdel(&ck->b);
	ft_memdel((void**)&ck);
	return (1);
}

static t_checker	*init_t_checker(t_checker *ck, int argc)
{
	if (!(ck = ft_memalloc(sizeof(t_checker)))
		|| !(ck->flags = ft_memalloc(sizeof(t_checker_flags)))
		|| !(ck->a = ft_tabnew(((size_t)(argc - 1))))
		|| !(ck->b = ft_tabnew(0)))
		return (NULL);
	ck->flags->l = 0;
	ck->flags->s = 10000;
	ck->flags->v = 0;
	ck->flags->c = 0;
	ck->argnb = 1;
	ck->a_size = 0;
	ck->b_size = 0;
	ck->rotation = 0;
	ck->nbrotations = 0;
	ck->error = 0;
	return (ck);
}

int					main(int argc, char **argv)
{
	t_checker		*ck;

	ck = NULL;
	if (argc < 2)
		return (checker_display_usage());
	if (!(ck = init_t_checker(ck, argc)) && del_t_checker(ck))
		return (checker_display_result(ERROR));
	checker_parsing_flags(ck, argc, argv);
	if (!(ck->a_size = argc - ck->argnb))
		ck->error = -1;
	if (ck->error && del_t_checker(ck))
		return (checker_display_result(ERROR));
	checker_parsing_integers(ck, argc, argv);
	if (ck->error && del_t_checker(ck))
		return (checker_display_result(ERROR));
	del_t_checker(ck);
	checker_display_result(OK);
	return (0);
}
