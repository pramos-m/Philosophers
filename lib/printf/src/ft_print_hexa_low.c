/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:38:50 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/18 13:01:22 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa_low(unsigned int hexa, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (hexa > 15)
	{
		count = ft_print_hexa_low(hexa / 16, count);
		if (count == -1)
			return (-1);
	}
	count = ft_print_char(base[hexa % 16], count);
	if (count == -1)
		return (-1);
	return (count);
}
