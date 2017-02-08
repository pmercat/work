/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:42:45 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 20:42:47 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

static	void	add_tetriminos_to_list(char *tetriminos, t_tetriminos list[27], 
						int index_tetris)
{
	int		i;
	int		index_points;
	t_point	origin;

	i = 0;
	origin.x = -1;
	origin.y = -1;
	index_points = 0;
	while (i < 20)
	{
		if (tetriminos[i] == '#')
		{
			if (origin.x == -1)
			{
				set_point(&origin, i % 5, i / 5);
				set_point(&(list[index_tetris].points[index_points]), 0, 0);
			}
			else
				set_point(&(list[index_tetris].points[index_points]), 
							i % 5 - origin.x, i / 5 - origin.y);
			index_points++;
		}
		i++;
	}
	list[index_tetris].name = 'A' + index_tetris;
}

void			ft_list_tetriminos(int fd, t_tetriminos list[27])
{
	int		read_size;
	int		index_tetris;
	char	tetriminos[20 + 1];

	index_tetris = 0;
	while ((read_size = read(fd, tetriminos, 21)))
	{
		add_tetriminos_to_list(tetriminos, list, index_tetris);
		index_tetris++;
	}
	list[index_tetris].name = '\0';
}
