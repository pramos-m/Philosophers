/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:03:03 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/17 17:36:01 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_decimal(int n, int count)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		count = ft_print_char('-', count);
		if (count == -1)
			return (-1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		count = ft_print_decimal(nbr / 10, count);
		if (count == -1)
			return (-1);
	}
	count = ft_print_char((nbr % 10) + '0', count);
	if (count == -1)
		return (-1);
	return (count);
}
