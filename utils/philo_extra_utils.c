/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_extra_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:26:47 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/24 17:47:18 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_utils.h>
#include <philosophers.h>

void	delete(void **dlt)
{
	free(*dlt);
	*dlt = NULL;
}

int	ft_check_isdigit(int params, char **str)
{
	int			i;
	long long	tmpnbr;

	i = 0;
	while (++i < params)
	{
		if (!ft_while_is_digit(str[i]) || !ft_is_int(str[i]))
			return (0);
		tmpnbr = ft_atoi(str[i]);
		if (!ft_check_maxint(tmpnbr))
			return (0);
	}
	return (1);
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

int	ft_is_int(char *num)
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
	if (ft_strlen(&num[i]) > 10)
		return (0);
	tmp = ft_atoi(num);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	return (1);
}

size_t	ft_strlen(const	char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (*str == character)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
