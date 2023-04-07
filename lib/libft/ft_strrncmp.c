/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:12:10 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/18 16:05:21 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	if (!n || !s1 || !s2)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (n && (s1[i] || s2[j]))
	{
		if (s1[i] != s2[j])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[j]);
		i--;
		j--;
		n--;
	}
	return (0);
}
