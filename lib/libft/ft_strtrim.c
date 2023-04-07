/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:19:07 by pramos-m          #+#    #+#             */
/*   Updated: 2022/11/28 17:35:17 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = (ft_strlen(s1) - 1);
	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	str = ft_substr(s1, i, j - i + 1);
	if (!str)
		return (NULL);
	return (str);
}
