# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 13:35:40 by gmorer            #+#    #+#              #
#    Updated: 2016/05/13 11:41:30 by gmorer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
SRC = \
	ft_argv.c\
	ft_free.c\
	lib_ft_ls.c\
	main.c\
	option.c\
	remplissagedebug.c\
	ft_print.c\
	ordre.c\
	init.c\
	libstrstr.c\
	prompt.c
CFLAGS = -Werror -Wextra -Wall
INC = libft/libft.a
LIB = libft/

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	make -C libft
	$(CC) $(CFLAGS) $(SRC) -L $(LIB) $(INC) -o $(NAME)

debug :
	make -C libft
	$(CC) $(CFLAGS) -g $(SRC) -L $(LIB) $(INC) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
