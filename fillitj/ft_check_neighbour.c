/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_neighbour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:02:22 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 20:40:07 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		number_of_neighbour(char *tetriminos, int i)
{
	int		nb_neighbours;

	nb_neighbours = 0;
	if (i % 5 - 1 >= 0 && tetriminos[i - 1] == '#')
		nb_neighbours++;
	if (i % 5 + 1 < 4 && tetriminos[i + 1] == '#')
		nb_neighbours++;
	if (i / 5 - 1 >= 0 && tetriminos[i - 5] == '#')
		nb_neighbours++;
	if (i / 5 + 1 < 4 && tetriminos[i + 5] == '#')
		nb_neighbours++;
	return (nb_neighbours);
}

int				ft_check_neighbour(char *tetriminos)
{
	int		i;
	int		nb_neighbours;
	int		two_pieces;

	i = 0;
	two_pieces = 0;
	while (i < 20)
	{
		if (tetriminos[i] == '#')
		{
			nb_neighbours = number_of_neighbour(tetriminos, i);
			if (nb_neighbours == 0)
				return (FAIL);
			if (nb_neighbours > 1)
				two_pieces = 1;
		}
		i++;
	}
	if (two_pieces == 0)
		return (FAIL);
	return (SUCCESS);
}
