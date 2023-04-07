/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:17 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/16 18:40:40 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_buffer(char *storage, char *buff)
{
	char	*str;

	if (!storage)
	{
		storage = malloc(sizeof(char) * 1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	str = ft_strjoin(storage, buff);
	ft_free_get(&storage);
	return (str);
}
