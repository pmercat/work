/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:15:37 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 21:18:50 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_file(char	*file)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		is_valid(char *buf)
{
	int	i;
	int	nbsharp;

	i = -1;
	nbsharp = 0;
	while (buf[++i] != '\0')
	{
		if ((i + 1) % 5 != 0 && i != 20)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
		}
		else
		{
			if (buf[i] != '\n')
				return (0);
		}
		if (buf[i] == '#')
			nbsharp++;
	}
	return (nbsharp == 4 ? 1 : 0);
}

t_total		*reader(int fd) //fonction incomplete cf last_tetri
{
	char	*buf;
	t_total *all;
	int		tetri;
	int		i;

	i = -1;
	if (!(all = ft_memalloc(sizeof(t_total))))
		exit(EXIT_FAILURE);
	if (!(buf = ft_strnew(21)))
	   exit(EXIT_FAILURE);
	while ((tetri = read(fd, buf, 21)) && ++i)  //open ouvrira 21 tant que ya du fd 
	{
		if(tetri < 20 && tetri > 0)
			return (NULL);
		if (is_valid(buf))
			make_piece(all, i, buf);
	}
	return (all);
}
