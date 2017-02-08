/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:54:49 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 21:58:47 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_nb_sharp(char *tetriminos)
{
	int		i;
	int		nb_sharp;

	i = 0;
	nb_sharp = 0;
	while (i < 20)
	{
		if (tetriminos[i] == '#')
			nb_sharp++;
		i++;
	}
	if (nb_sharp != 4)
		return (FAIL);
	return (SUCCESS);
}

static int		check_valid_char(char *tetriminos, int piece)
{
	int		i;

	i = 0;
	while (i < 21)
	{
		if (INDEX_NEWLINE(i) && tetriminos[i] != '\n')
			return (FAIL);
		else if (SEPA_TETRI(i) && piece == NO_LAST_PIECE && tetriminos[i] !='\n')
			return (FAIL);
		else if (!INDEX_NEWLINE(i) && !SEPA_TETRI(i) && (tetriminos[i] != '#' && tetriminos[i] != '.'))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int		check_tetriminos(char *tetriminos, int piece)
{
	if ((check_valid_char(tetriminos, piece)) == FAIL)
		return (FAIL);
	if ((check_nb_sharp(tetriminos)) == FAIL)
		return (FAIL);
	if ((ft_check_neighbour(tetriminos)) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int				ft_check_file(int fd)
{
	int		nb_tetriminos;
	int		read_size;
	char	tetriminos[20 + 1];

	nb_tetriminos = 0;
	while ((read_size = read(fd, tetriminos, 21)) == 21)
	{
		if ((check_tetriminos(tetriminos, NO_LAST_PIECE)) == FAIL)
			return (FAIL);
		nb_tetriminos++;
	}
	nb_tetriminos++;
	if (read_size != 20 || nb_tetriminos > MAX_TETRI || (check_tetriminos(tetriminos, LAST_PIECE) == FAIL))
		return (FAIL);
	return (SUCCESS);
}
