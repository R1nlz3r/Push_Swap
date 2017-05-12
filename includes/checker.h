/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:44:10 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/12 18:31:24 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "../libft/libft.h"
# include "fcntl.h"

# define ERROR -1
# define OK 0
# define KO 1

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct		t_checker_flags
{
	int				l;
	int				s;
	int				v;
	int				c;
}					t_checker_flags;

typedef struct		s_checker
{
	t_checker_flags *flags;
	int				*a;
	int				*b;
	int				a_size;
	int				b_size;
	int				rotation;
	int				nbrotations;
	int				argnb;
	int				error;
}					t_checker;

t_checker			*checker_parsing_flags(t_checker *ck, int argc,
	char **argv);
t_checker			*checker_parsing_integers(t_checker *ck, int argc,
	char **argv);
void				checker_display_start(void);
int					checker_display_usage(void);
int					checker_display_result(int result);
void				checker_display_rotation(t_checker *ck);
void				checker_display_nbrotations(t_checker *ck);
void				checker_display_stacks(t_checker *ck);

#endif
