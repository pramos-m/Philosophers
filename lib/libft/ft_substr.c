/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:12:18 by pramos-m          #+#    #+#             */
/*   Updated: 2022/11/26 14:02:02 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || !*s)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[start] != '\0' && j < len)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
