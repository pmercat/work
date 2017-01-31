/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:08:18 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:49:27 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	xy_upleft(t_tetris *piece)
{
	int	i;
	int	j;
	int	t;

	i = piece->block[0].x;
	j = piece->block[0].y;
	t = 0;
	while (t < 4)
	{
		piece->block[t].x -= i;
		piece->block[t].y -= j;
		t++;
	}
}

void	make_xy(char *str, t_total *all, int t)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			all->piece[t].block[j].x = i % 5;
			all->piece[t].block[j].y = i / 5;
			j++;
		}
		i++;	
	}
	xy_upleft(&(all->piece[t]));
}

void	make_piece(t_total *all, int rank, char *buf)
{
	all->nb_piece++;
	make_xy(buf, all, rank);
	all->piece[rank].alpha = all->nb_piece + 64;
}
