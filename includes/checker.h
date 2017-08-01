/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:44:10 by mapandel          #+#    #+#             */
/*   Updated: 2017/07/26 23:02:07 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "libft.h"
# include "fcntl.h"

# define ERROR -1
# define OK 0
# define KO 1

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

typedef struct		t_checker_flags
{
	int				l;
	int				s;
	int				v;
}					t_checker_flags;

typedef struct		s_checker
{
	t_checker_flags *flags;
	t_tab			*a;
	t_tab			*b;
	int				rotation;
	int				nbrotations;
	int				argnb;
	int				fd;
	char			*line;
	int				error;
	char			pad_0[4];
}					t_checker;

t_checker			*checker_parsing_flags(t_checker *ck, int argc,
	char **argv);
t_checker			*checker_parsing_bash_arg(t_checker *ck, char **argv);
t_checker			*checker_parsing_integers(t_checker *ck, int argc,
	char **argv);
void				checker_parsing_doubles(t_checker *ck);
t_checker			*checker_parsing_movements(t_checker *ck);
t_checker			*checker_movements(t_checker *ck);
int					checker_display_usage(void);
int					checker_display_result(int result);
void				checker_display_v_flag(t_checker *ck);


#endif
