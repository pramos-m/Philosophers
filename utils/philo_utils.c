/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:49:55 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/12 13:00:03 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_error_handler(int error, char *strerror)
{
	if (!strerror && error)
	{
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERRMSG0, ft_strlen(ERRMSG0));
		else if (error == ERRCODE1)
			write(STDERR_FILENO, ERRMSG1, ft_strlen(ERRMSG1));
		else if (error == ERRCODE2)
			write(STDERR_FILENO, ERRMSG2, ft_strlen(ERRMSG2));
		else if (error == ERRCODE3)
			write(STDERR_FILENO, ERRMSG3, ft_strlen(ERRMSG3));
		else if (error == ERRCODE4)
			write(STDERR_FILENO, ERRMSG4, ft_strlen(ERRMSG4));
	}
	else if ((!error) && (strerror))
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	else if ((!error) && (!strerror))
		perror("Error! ");
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char	*str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	ptr = (char *)malloc(size * count);
	if (!ptr)
		return (0);
	len = count * size;
	i = 0;
	while (i < len)
		ptr[i++] = 0;
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
