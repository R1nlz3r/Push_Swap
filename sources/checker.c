/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:47:12 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/06 20:09:53 by mapandel         ###   ########.fr       */
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
		|| !(ck->a = ft_tabnew(((size_t)(argc - 1))))
		|| !(ck->b = ft_tabnew(0)))
		return (NULL);
	ck->a_size = (size_t)(argc - 1);
	ck->b_size = 0;
	ck->error = 0;
	return (ck);
}

int					main(int argc, char **argv)
{
	t_checker		*ck;

	ck = NULL;
	if (argc < 2)
		return (checker_display(KO));
	if (!(ck = init_t_checker(ck, argc)) && del_t_checker(ck))
		return (checker_display(KO));
	ck = checker_parsing(ck, argv);
	if (ck->error && del_t_checker(ck))
		return (checker_display(KO));
	//resolve
	del_t_checker(ck);
	checker_display(OK);
	return (0);
}
