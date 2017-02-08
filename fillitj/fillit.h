/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:07:53 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 21:57:44 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR (-3)
# define USAGE (-2)
# define FAIL (-1)
# define SUCCESS 0

# define SIZE_PIECE 4
# define FIRST_PIECE 0
# define NEXT_PIECE(i) ((i) + 1)
# define LAST_PIECE 2
# define NO_LAST_PIECE 3

# define INDEX_NEWLINE(i) ((i) % 5 == 4)
# define SEPA_TETRI(i) ((i == 20))

# define MAX_TETRI 26

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_point
{
	int	x;
	int y;
}					t_point;

typedef	struct		s_tetriminos
{
	char 		name;
	t_point		points[4];
}					t_tetriminos;

int		ft_check_file(int fd);
int		ft_check_neighbour(char *tetriminos);
void	ft_list_tetriminos(int fd, t_tetriminos list[27]);
void	ft_print_solution(char *map_solution, int size_of_side);
int		ft_resolve_fillit(t_tetriminos list[27], char **map_solution);
int		ft_set_piece_on_map(t_tetriminos tetriminos, char *map_solution, int size_of_side, int current_position);
void	*ft_memalloc(size_t size);
int		ft_delete_piece_on_map(t_tetriminos tetriminos, char *map_solution, int size_of_side, int current_position);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
char	*ft_strnew(size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif
