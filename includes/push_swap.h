/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:47:39 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/04 21:56:31 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_push_swap
{
	t_tab			*a;
	t_tab			*b;
	int				l;
	int				argnb;
}					t_push_swap;

t_push_swap			*push_swap_parsing_flags(t_push_swap *ps, int argc,
	char **argv);
t_push_swap			*push_swap_parsing_integers(t_push_swap *ps, int argc,
	char **argv);

#endif
