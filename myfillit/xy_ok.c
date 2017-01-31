/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:34:18 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:08:31 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xy_id(t_point b1, t_point b2)
{
	if (b1.x == b2.x)
		return (1);
	if (b1.y == b2.y)
		return (1);
	return (0);
}

int		xy_prox(t_point b1, t_point b2)
{
	if (b1.x == b2.x - 1 || b1.x == b2.x + 1)
		return (1);
	if (b1.y == b2.y - 1 || b1.y == b2.y + 1)
		return (1);
	return (0);
}

int		xy_good(t_point b1, t_point b2)
{
	if (xy_id(b1, b2))
		if (xy_prox(b1, b2))
			return (1);
	return (0);		
}

int		two_xy_prox(t_tetris piece)
{
	int	i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (xy_good(piece.block[i], piece.block[j])
						&& xy_good(piece.block[i], piece.block[k])
						&&	i != j && i != k && j != k)
					return (1);
			k++;	
			}
		j++;	
		}
	i++;	
	}
	return (0);
}

int		tetri_valid(t_tetris piece)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (two_xy_prox(piece))
	{
		while (i < 4)
		{
			while (j < 4 && !(xy_good(piece.block[i], piece.block[j])))
				j++;
			if (j == 4)
				return (0);
			i++;
		}
		return (1);	
	}
	return (0);
}
