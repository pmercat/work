/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:27:08 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 22:04:04 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		error(int type_error)
{
	if (type_error == USAGE)
		ft_putstr("usage: fillit file_path\n");
	if (type_error == ERROR)
		ft_putstr("error\n");
	return (FAIL);
}

static int		fillit(char *file_name)
{
	int				fd;
	t_tetriminos	*list;
	char			*map_solution;
	int				size_side_square;

	if(!(list = ft_memalloc(sizeof(t_tetriminos) * 27)))
		return (FAIL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (FAIL);
	ft_list_tetriminos(fd, list);
	size_side_square = ft_resolve_fillit(list, &map_solution);
	ft_print_solution(map_solution, size_side_square);
	free(map_solution);
	free(list);
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	int 	fd;

	if (argc != 2)
		return (error(USAGE));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (error(ERROR));
	if ((ft_check_file(fd)) == FAIL)
		return (error(ERROR));
	close (fd);
	if (fillit(argv[1]) == FAIL)
		return (error(ERROR));
	return (SUCCESS);
}
