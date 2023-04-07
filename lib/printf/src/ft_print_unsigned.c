/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:19:14 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/17 16:41:23 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int n, int count)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		count = ft_print_unsigned(n / 10, count);
		if (count == -1)
			return (-1);
	}
	count = ft_print_char(n % 10 + '0', count);
	if (count == -1)
		return (-1);
	return (count);
}
