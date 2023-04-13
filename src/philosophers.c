/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:24 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/13 19:49:12 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_num_arg(char *num_arg, int pos, t_list *table)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (pos == 1 && n > 200) || (pos == 2 && n < 60)
		|| (pos == 3 && n < 60) || (pos == 4 && n < 60))
	{
		ft_error_handler(0, "eliminame");
		write(1, "Numero incorrecto.\n", 20);
		return (-1);
	}
	else
	{
		if (pos == 1)
			table->num_philos = n;
		if (pos == 2)
			table->time_die = n;
		if (pos == 3)
			table->time_eat = n;
		if (pos == 4)
			table->time_sleep = n;
		if (pos == 5)
			table->philo_eats = n;
		return (n);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*table;

	if (argc != 5 && argc != 6)
		ft_error_handler(0, "Numero de argumentos no valido.\n");
	i = 0;
	table = malloc(sizeof(t_list));
	if (!table)
		return (0);
	check_num_arg(argv[i], 0, table);
	while (++i != argc)
		if (check_num_arg(argv[i], i, table) < 0)
			return (0);
	init_table(table);
	init_mutex(table);
	start_simulation(table);
	return (0);
}
