/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:16 by pramos-m          #+#    #+#             */
/*   Updated: 2022/11/06 13:41:00 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!r)
		return (NULL);
	ft_memcpy(r, s1, ft_strlen(s1) + 1);
	return (r);
}
