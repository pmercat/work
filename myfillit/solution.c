/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:38:55 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:23:04 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search_to_solve(t_total *all, int nb, char *grid, int pos)
{
	if (nb == all->nb_piece)
		return (1);
	while (grid[pos])
	{
		if (does_it_fit(all->piece[nb], grid, pos))
		{
			if (search_to_solve(all, nb + 1, grid, 0))
				return (1);
			else 
			{
				rm_piece(all->piece[nb], grid);
				return (search_to_solve(all, nb, grid, pos + 1));
			}
		}
		pos++;
	}
	return (0);
}

char	*solution(t_total *all)
{
	char	*grid;
	int		size;

	size = 2;
	grid = make_grid(size);
	while (search_to_solve(all, 0, grid, 0) == 0)
	{
		size++;
		free(grid);
		grid = make_grid(size);
	}
	return (grid);
}
