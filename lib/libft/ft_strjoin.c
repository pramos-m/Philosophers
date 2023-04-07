/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:21:56 by pramos-m          #+#    #+#             */
/*   Updated: 2023/03/09 10:04:32 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;
	size_t	newlen;

	newlen = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}	
	new = (char *)ft_calloc((newlen + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i + j] = s2[j];
	return (new);
}
