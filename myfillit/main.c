/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:10:34 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:16:39 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fillit(char *argv)
{
	char	*grid;
	int 	i;
	int		fd;
	t_total	*all;

	i = -1;
	fd = open_file(argv);
	if (!(all = reader(fd)))
	{
		ft_putendl("error");
		return ;
	}
	while (++i < all->nb_piece)
	{
		if (!(tetri_valid(all->piece[i])))
		{
			ft_putendl("error");
			return ;
		}
	}	
	grid = solution(all);
	free(all);
	ft_putstr(grid);
	free(grid);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{	
		ft_putendl("usage: ./fillit file_name");
		return (0);
	}
	else 
		fillit(argv[1]);
}
