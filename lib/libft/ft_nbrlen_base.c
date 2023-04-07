/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:36:12 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 17:14:25 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_nbrlen_base(long long nbr, long long len)
{
	int	nbr_size;

	nbr_size = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr_size++;
		nbr /= len;
	}
	return (nbr_size);
}
