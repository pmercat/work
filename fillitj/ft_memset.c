/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:54:38 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 21:32:25 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	size_t			i;

	uc = c;
	i = 0;
	while (i < len)
	{
		((char*)b)[i] = uc;
		i++;
	}
	return (b);
}
