/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:58:42 by pramos-m          #+#    #+#             */
/*   Updated: 2022/09/24 16:45:22 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	ptr = (char *)malloc(size * count);
	if (!ptr)
		return (0);
	len = count * size;
	i = 0;
	while (i < len)
		ptr[i++] = 0;
	return (ptr);
}
