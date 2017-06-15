/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:47:39 by mapandel          #+#    #+#             */
/*   Updated: 2017/06/07 21:28:36 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct		s_push_swap
{
	t_tab			*a;
	t_tab			*b;
	int				l;
	int				argnb;
	int				fd;
	int				median;
}					t_push_swap;

t_push_swap			*push_swap_parsing_flags(t_push_swap *ps, int argc,
	char **argv);
t_push_swap			*push_swap_parsing_integers(t_push_swap *ps, int argc,
	char **argv);
t_push_swap			*push_swap_solver(t_push_swap *ps);
void				push_swap_display_usage(void) __attribute__ ((noreturn));
void				push_swap_display_movements(t_push_swap *ps, int mv);

#endif
