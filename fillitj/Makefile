# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmercat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 18:19:08 by pmercat           #+#    #+#              #
#    Updated: 2017/02/08 21:15:18 by pmercat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
		ft_check_file.c \
		ft_check_neighbour.c \
		ft_list_tetriminos.c \
		ft_resolve_fillit.c \
		ft_set_or_delete_piece.c \
		ft_print_solution.c \
		ft_strlen.c \
		ft_putstr.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_memset.c \
		ft_strnew.c \

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAG) $(SRCS)
	$(CC) -o $(NAME) $(OBJ)

clean:
		/bin/rm -rf $(OBJ)

fclean: clean
		/bin/rm -rf $(NAME)
re: fclean all
