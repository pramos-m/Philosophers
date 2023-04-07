/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:18 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 16:26:38 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrixlen(char **matrix)
{
	int	len;

	len = 0;
	if (!matrix)
		return (0);
	while (matrix[len])
		len++;
	return (len);
}
