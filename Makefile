# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 02:39:44 by mapandel          #+#    #+#              #
#    Updated: 2017/09/09 13:58:15 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER =	checker
P_S =		push_swap

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror -Weverything

#			Sources

CHECK_SRC =	sources/checker.c \
			sources/checker_parsing.c \
			sources/checker_parsing2.c \
			sources/checker_movements.c \
			sources/checker_display.c \
			sources/checker_display2.c \

P_S_SRC =	sources/push_swap.c \
			sources/push_swap_parsing.c \
			sources/push_swap_solve.c \
			sources/push_swap_solve2.c \
			sources/push_swap_display.c \

CHECK_OBJ =	$(CHECK_SRC:.c=.o)
P_S_OBJ =	$(P_S_SRC:.c=.o)

INC =		includes

#			Library Path

LIBPATH =	libft/libft.a

LIBINC	=	libft/includes

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

.PHONY: all re glu clean fclean

all: $(CHECKER) $(P_S)

$(CHECKER):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Checker::--$(DEF)"
	@make $(CHECK_OBJ)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJ) $(LIBPATH)

$(P_S):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Push_swap::--$(DEF)"
	@make $(P_S_OBJ)
	@$(CC) $(CFLAGS) -o $(P_S) $(P_S_OBJ) $(LIBPATH)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -I $(LIBINC) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(CHECK_OBJ) $(P_S_OBJ)

fclean: clean
	@echo "$(RED)--::Executables and Library Delection::--$(DEF)"
	@rm -rf $(CHECKER) $(P_S) $(LIBPATH)
