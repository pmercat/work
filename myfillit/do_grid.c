/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:07 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:09:33 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_grid(int size)
{
	int		i;
	char 	*grid;

	i = 0;
	if (!(grid = ft_strnew((size + 1) * size)))
		exit(EXIT_FAILURE);
	while (i < ((size + 1) * size))
	{
		if ((i + 1) % (size + 1) != 0)
			grid[i] = '.';
		else
			grid[i] = '\n';
		i++;
	}
	return (grid);
}

int		does_it_fit(t_tetris piece, char *grid, int pos)
{
	int		posfit;
	int		size;
	int		k;

	size = 0;
	while (grid[size] != '\n')
		size++;
	k = 0;
	while (k < 4)
	{
		posfit = (piece.block[k].x + (size + 1) * (piece.block[k].y) + pos);
		if (grid[posfit] != '.' || posfit >= size * (size + 1)
			   || ((posfit + 1) % (size + 1) != 0))
			   return (0);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		posfit = (piece.block[k].x + (size + 1) * (piece.block[k].y) + pos);
		grid[posfit] = piece.alpha;
		k++;
	}
	return (1);
}

void	rm_piece(t_tetris piece, char *grid)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (grid[i] && k < 4)
	{
		if (grid[i] == piece.alpha)
		{
			grid[i] = '.';
			k++;
		}
		i++;
	}
}
