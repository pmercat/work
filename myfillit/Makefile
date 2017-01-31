# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmercat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 16:24:19 by pmercat           #+#    #+#              #
#    Updated: 2017/01/31 21:07:51 by pmercat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c\
	   	reader.c\
	   	do_grid.c\
	   	solution.c\
	   	xy_ok.c\
	   	make_piece.c\
	   	ft_putendl.c\
	   	ft_putstr.c\
	   	ft_memalloc.c\
	   	ft_strnew.c\
	   	ft_putchar.c\
		ft_strlen.c\

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAG) $(SRCS)
	$(CC) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
