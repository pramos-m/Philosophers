/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:00:47 by pramos-m          #+#    #+#             */
/*   Updated: 2022/09/22 15:40:35 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	k;

	lendest = 0;
	while (dst[lendest] != '\0')
	{
		lendest++;
	}
	lensrc = 0;
	while (src[lensrc] != '\0')
	{
		lensrc++;
	}
	k = 0;
	if (size <= lendest)
		return (size + lensrc);
	while (src[k] != '\0' && lendest + k + 1 < size)
	{
		dst[lendest + k] = src[k];
		k++;
	}
	dst[lendest + k] = '\0';
	return (lensrc + lendest);
}
