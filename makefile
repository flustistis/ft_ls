# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 13:35:40 by gmorer            #+#    #+#              #
#    Updated: 2016/02/21 14:03:11 by gmorer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
SRC = \
	optiondebug.c
CFLAGS = -Werror -Wall -Wextra
INC = libft/libft.a
LIB = libft/

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	make -C libft
	$(CC) $(CFLAGS) $(SRC) -L $(LIB) $(INC) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
