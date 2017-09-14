/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:46:54 by mapandel          #+#    #+#             */
/*   Updated: 2017/09/14 18:10:14 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				del_t_push_swap(t_push_swap *ps)
{
	ft_tabdel(&ps->a);
	ft_tabdel(&ps->b);
	ft_memdel((void**)&ps);
}

static t_push_swap		*init_t_push_swap(t_push_swap *ps)
{
	if (!(ps = ft_memalloc(sizeof(t_push_swap)))
		|| !(ps->a = ft_tabnew(1000000))
		|| !(ps->b = ft_tabnew(1000000)))
		exit(-1);
	ps->l = 0;
	ps->argnb = 1;
	ps->fd = 1;
	ps->median = 0;
	ps->lastmove = 0;
	ps->lastmove_count = 0;
	return (ps);
}

int						main(int argc, char **argv)
{
	t_push_swap		*ps;

	ps = NULL;
	if (argc < 2)
		push_swap_display_usage();
	ps = init_t_push_swap(ps);
	ps = push_swap_parsing_flags(ps, argc, argv);
	if (!(ps->a->len = (size_t)(argc - ps->argnb)))
		push_swap_display_error();
	if (ps->a->len == 1)
		ps = push_swap_parsing_bash_arg(ps, argv);
	else
		ps = push_swap_parsing_integers(ps, argc, argv);
	push_swap_parsing_doubles(ps);
	ps->a = ft_tabrev_leakless(ps->a);
	ps = push_swap_solver(ps);
	del_t_push_swap(ps);
	return (0);
}
