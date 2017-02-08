/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmercat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:27:00 by pmercat           #+#    #+#             */
/*   Updated: 2017/02/08 19:15:53 by pmercat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*output;

	if (!(output = (char*)ft_memalloc(size + 1)))
		return (NULL);
	output[size] = '\0';
	return (output);
}
