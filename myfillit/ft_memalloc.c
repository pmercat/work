/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:02:05 by pmercat           #+#    #+#             */
/*   Updated: 2017/01/31 20:19:53 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*output;

	if (!(output = malloc(size)))
		return (NULL);
	ft_bzero(output, size);
	return (output);
}
