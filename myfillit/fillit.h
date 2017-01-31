/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:19:42 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:19:44 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef	struct		s_tetris
{
	char	alpha;
	t_point	block[4];
}					t_tetris;

typedef	struct		s_total
{
	int		nb_piece;
	t_tetris piece[26];   // piece[rank]
}					t_total;


char	*make_grid(int size);
void	xy_upleft(t_tetris *piece);
void	make_xy(char *str, t_total *all, int t);
int		open_file(char *file);
int		is_valid(char *buf);
t_total	*reader(int fd);
void	make_piece(t_total *all, int rank, char *buf);
int		does_it_fit(t_tetris piece, char *grid, int pos);
void	rm_piece(t_tetris piece, char *grid);
int		search_to_solve(t_total *all, int nb, char *grid, int pos);
char	*solution(t_total *all);
int		xy_id(t_point b1, t_point b2);
int		xy_prox(t_point b1, t_point b2);
int		two_xy_prox(t_tetris piece);
int		tetri_valid(t_tetris piece);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
void	ft_putchar(char c);

#endif
