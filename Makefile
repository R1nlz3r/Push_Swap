# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 02:39:44 by mapandel          #+#    #+#              #
#    Updated: 2017/05/12 18:45:07 by mapandel         ###   ########.fr        #
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
			sources/checker_display.c \
			sources/checker_display2.c \

P_S_SRC =

CHECK_OBJ =	$(CHECK_SRC:.c=.o)
P_S_OBJ =	$(P_S_SRC:.c=.o)

INC =		includes

#			Library Path

LIBPATH =	libft/libft.a

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

all: $(CHECKER) $(P_S)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(CHECK_OBJ) $(P_S_OBJ)

fclean: clean
	@echo "$(RED)--::Executables and Library Delection::--$(DEF)"
	@rm -rf $(CHECKER) $(P_S) $(LIBPATH)
