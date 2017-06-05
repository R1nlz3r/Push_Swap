/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:46:54 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/05 01:58:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				del_t_push_swap(t_push_swap *ps)
{
	ft_tabdel(&ps->a);
	ft_tabdel(&ps->b);
	ft_memdel((void**)&ps);
}

static t_push_swap		*init_t_push_swap(t_push_swap *ps, int argc)
{
	if (!(ps = ft_memalloc(sizeof(t_push_swap)))
		|| !(ps->a = ft_tabnew((size_t)(argc - 1)))
		|| !(ps->b = ft_tabnew((size_t)(argc - 1))))
		exit(-1);
	ps->l = 0;
	ps->argnb = 1;
	return (ps);
}

int		main(int argc, char **argv)
{
	t_push_swap		*ps;

	ps = NULL;
	if (argc < 2)
		return (-1);//return (push_swap_display_usage());
	ps = init_t_push_swap(ps, argc);
	ps = push_swap_parsing_flags(ps, argc, argv);
	if (!(ps->a->len = (size_t)(argc - ps->argnb)))
		exit(-1);
	ps = push_swap_parsing_integers(ps, argc, argv);
	del_t_push_swap(ps);
	return (0);
}
