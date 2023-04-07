/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:38:50 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/17 18:23:04 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa_up(unsigned int hexa, int count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (hexa > 15)
	{
		count = ft_print_hexa_up(hexa / 16, count);
		if (count == -1)
			return (-1);
	}
	count = ft_print_char(base[hexa % 16], count);
	if (count == -1)
		return (-1);
	return (count);
}
