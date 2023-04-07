/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:51 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 17:34:18 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *num)
{
	int			i;
	long long	tmp;

	i = 0;
	if (!num || !*num)
		return (0);
	if (ft_strchr("+-", num[i]))
		i++;
	while (num[i] && num[i] == '0')
		i++;
	if (!num[i])
		i--;
	if (ft_strlen(&num[i]) > ft_nbrlen_base(INT_MAX, 10))
		return (0);
	tmp = ft_atol(num);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	return (1);
}
