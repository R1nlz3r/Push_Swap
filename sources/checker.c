/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/10 14:59:54 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			del_t_checker(t_checker *ck)
{
	ft_tabdel(&ck->a);
	ft_tabdel(&ck->b);
	ft_memdel((void**)&ck->flags);
	ft_memdel((void**)&ck);
	return (1);
}

static t_checker	*init_t_checker(t_checker *ck)
{
	if (!(ck = ft_memalloc(sizeof(t_checker)))
		|| !(ck->flags = ft_memalloc(sizeof(t_checker_flags)))
		|| !(ck->a = ft_tabnew(1000000))
		|| !(ck->b = ft_tabnew(1000000)))
		return (NULL);
	ck->flags->l = 0;
	ck->flags->s = 10000;
	ck->flags->v = 0;
	ck->argnb = 1;
	ck->rotation = 0;
	ck->nbrotations = 0;
	ck->fd = 0;
	ck->error = 0;
	return (ck);
}

static int			main2(t_checker *ck)
{
	ck->a = ft_tabrev_leakless(ck->a);
	ck = checker_movements(ck);
	if (ck->error == -1 && del_t_checker(ck))
		return (checker_display_result(KO));
	else if (ck->error == 1 && del_t_checker(ck))
		return (checker_display_result(ERROR));
	del_t_checker(ck);
	return (checker_display_result(OK));
}

int					main(int argc, char **argv)
{
	t_checker		*ck;

	ck = NULL;
	if (argc < 2)
		return (checker_display_usage());
	if (!(ck = init_t_checker(ck)) && del_t_checker(ck))
		return (checker_display_result(ERROR));
	ck = checker_parsing_flags(ck, argc, argv);
	if (!(ck->a->len = (size_t)(argc - ck->argnb)))
		ck->error = -1;
	if (ck->error && del_t_checker(ck))
		return (checker_display_result(ERROR));
	if (ck->a->len == 1)
		ck = checker_parsing_bash_arg(ck, argv);
	else
		ck = checker_parsing_integers(ck, argc, argv);
	if (ck->error && del_t_checker(ck))
		return (checker_display_result(ERROR));
	checker_parsing_doubles(ck);
	if (ck->error && del_t_checker(ck))
		return (checker_display_result(ERROR));
	return (main2(ck));
}
