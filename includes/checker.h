/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:44:10 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/06 19:57:06 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include "../libft/libft.h"

# define ERROR -1
# define OK 0
# define KO 1

typedef struct		s_checker
{
	int				*a;
	int				*b;
	size_t			a_size;
	size_t			b_size;
	int				error;
	char			pad_0[4];
}					t_checker;

t_checker			*checker_parsing(t_checker *ck, char **argv);
int					checker_display(int result);

#endif
