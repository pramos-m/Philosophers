/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:49:55 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/25 13:24:48 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

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

int	ft_check_isdigit(int params, char **str)
{
	int			i;
	long long	tmpnbr;

	i = 0;
	while (++i < params)
	{
		if (!ft_while_is_digit(str[i]) || !ft_is_int(str[i]))
			return (1);
		tmpnbr = ft_atoi(str[i]);
		if (!ft_check_maxint(tmpnbr))
			return (1);
	}
	return (0);
}

int	ft_while_is_digit(char *num)
{
	int	i;

	i = 0;
	if ((num[0] == '-' || num[0] == '+') && num[1])
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
			i++;
	}
	return (1);
}

int	ft_check_maxint(long long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
