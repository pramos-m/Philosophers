/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:27:00 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/16 19:14:49 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstrwc(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
			count++;
		}
	}
	return (count);
}

static int	ft_len(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	*ft_error_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_countstrwc(s, c) + 1));
	if (!str)
		return (NULL);
	while (j < ft_countstrwc(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = (ft_substr(s, i, ft_len(s, i, c)));
		if (!str[j])
			return (ft_error_split(str));
		i += ft_len(s, i, c);
		j++;
	}
	str[j] = 0;
	return (str);
}
