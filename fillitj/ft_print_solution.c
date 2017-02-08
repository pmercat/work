/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:09:36 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 20:43:22 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_solution(char *map_solution, int size_of_side)
{
	int		i;

	i = 0;
	while (i < size_of_side)
	{
		write(1, map_solution + i * size_of_side, size_of_side);
		write(1, "\n", 1);
		i++;
	}
}
