/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:44:50 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/04 10:50:35 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (matrix)
	{
		while (matrix[++i])
		{
			free(matrix[i]);
			matrix[i] = NULL;
		}
		free(matrix);
		matrix = NULL;
	}
}
