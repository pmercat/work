/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_or_delete_piece.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 21:16:35 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 21:24:39 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set_piece_on_map(t_tetriminos tetriminos, char *map_solution, 
							int	size_of_side, int current_position)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = current_position % size_of_side + tetriminos.points[i].x;
		y = current_position / size_of_side + tetriminos.points[i].y;
		if (x < 0 || x >= size_of_side || y < 0 || x > size_of_side || map_solution[y * size_of_side + x] != '.')
			return (FAIL);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		x = current_position % size_of_side + tetriminos.points[i].x;
		y = current_position / size_of_side + tetriminos.points[i].y;
		map_solution[y * size_of_side + x] = tetriminos.name;
		i++;
	}
	return (SUCCESS);
}

int		ft_delete_piece_on_map(t_tetriminos tetriminos, char *map_solution, int size_of_side, int current_position)
{
	int i;
	int	x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = current_position % size_of_side + tetriminos.points[i].x;
		y = current_position / size_of_side + tetriminos.points[i].y;
		map_solution[y * size_of_side + x] = '.';
		i++;
	}
	return (SUCCESS);
}
