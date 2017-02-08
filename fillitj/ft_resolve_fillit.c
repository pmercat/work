/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_fillit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:13:13 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 20:46:09 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		init_of_size_side(t_tetriminos list[27])
{
	int		nb_tetriminos;
	int		size_of_side;

	nb_tetriminos = 0;
	size_of_side = 0;
	while (list[nb_tetriminos].name != '\0')
		nb_tetriminos++;
	while (size_of_side * size_of_side < nb_tetriminos * SIZE_PIECE)
		size_of_side++;
	return (size_of_side);
}

static int		search_sol(char *map_solution, int size_of_side_square, t_tetriminos list[27], int numero_of_piece)
{
	int		i;

	i = 0;
	if (list[numero_of_piece].name == '\0')
		return (SUCCESS);
	while (map_solution[i])
	{
		if (map_solution[i] == '.')
		{
			if (ft_set_piece_on_map(list[numero_of_piece], map_solution, 
									size_of_side_square, i) == SUCCESS)
			{
				if (search_sol(map_solution, size_of_side_square, list, NEXT_PIECE(numero_of_piece)) == SUCCESS)
						return (SUCCESS);
				ft_delete_piece_on_map(list[numero_of_piece], map_solution,
									size_of_side_square, i);
			}
		}
		i++;
	}
	return (FAIL);
}

int		ft_resolve_fillit(t_tetriminos list[27], char **map_solution)
{
	int		size_of_side_square;
	int		area_of_square;

	size_of_side_square = init_of_size_side(list);
	while (1)
	{
		area_of_square = size_of_side_square * size_of_side_square;
		if (!(*map_solution = ft_strnew(area_of_square)))
			return (FAIL);
		*map_solution = ft_memset(*map_solution, '.', area_of_square);
		if (search_sol(*map_solution, size_of_side_square, list, FIRST_PIECE) == SUCCESS)
			return (size_of_side_square);
		free(*map_solution);
		size_of_side_square++;
	}
	return (SUCCESS);

}
