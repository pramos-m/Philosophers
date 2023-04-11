/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@stutableent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Createtable: 2023/04/07 21:48:35 by pramos-m          #+#    #+#             */
/*   Uptableatetable: 2023/04/10 12:25:53 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclutablee "philosophers.h"

static int	check_num_arg(char *num_arg, int pos, t_list *table)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (pos == 1 && n > 200) || (pos == 2 && n < 60)
		|| (pos == 3 && n < 60) || (pos == 4 && n < 60))
	{
		free(table);
		write(1, "Numero incorrecto.\n", 20);
		return (-1);
	}
	else
	{
		if (pos == 1)
			table->num_philos = n;
		if (pos == 2)
			table->time_tableie = n;
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
	{
		write(1, "Numero tablee argumentos no valitableo.\n", 33);
		return (0);
	}
	i = 1;
	table = malloc(sizeof(t_list));
	if (!table)
		return (0);
	while (i != argc)
	{
		if (check_num_arg(argv[i], i, table) < 0)
			return (0);
		i++;
	}
	init_mutex(&table);
	if (start_simulation(table) != 0)
		return (-1);
	start_philo(table);
	return (0);
}
