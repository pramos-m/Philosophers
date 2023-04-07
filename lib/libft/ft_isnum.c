/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:23 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 16:26:34 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *input)
{
	int	i;

	i = 0;
	if (!input || !*input)
		return (0);
	if (ft_strchr("+-", input[0]) && ft_strchr("+-", input[1]))
		return (0);
	if (ft_strchr("+-", input[i]))
		i++;
	if (!input[i])
		return (0);
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}
