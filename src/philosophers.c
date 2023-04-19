/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:24 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/19 12:35:14 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int ac, char **av)
{
	int	*num;
	int	i;

	i = 0;
	num = NULL;
	if (!av[1] || !av[2] || !av[3] || !av[4])
		return (-1);
	while (++i < ac)
	{
		num[i] = ft_atoi(av[i]);
		if (num[i] < 0)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*table;
	t_times	times;

	if (ac != 5 && ac != 6)
		ft_error_handler(ERRCODE0, NULL);
	table = malloc(sizeof(t_list));
	if (!table)
		return (0);
	if (check_arg(ac, av) < 0)
		ft_error_handler(ERRCODE1, NULL);
	times = init_times(av, table);
	init_table(table, &times);
	init_mutex(table);
	start_simulation(table);
	return (0);
}
