/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:34:24 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/24 13:43:23 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	i;

	i = -1;
	sign = 1;
	result = 0;
	if (str[++i] == '-')
		sign = -1;
	while (str[i] != '\0' && str_base <= 16)
	{
		result *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += str[i] - '7';
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += str[i] - 'W';
		i++;
	}
	return (result * sign);
}
