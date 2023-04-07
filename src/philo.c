/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:48:35 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/07 22:13:42 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_num_arg(char *num_arg, int pos, t_list *d)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (pos == 1 && n > 200) || (pos == 2 && n < 60)
		|| (pos == 3 && n < 60) || (pos == 4 && n < 60))
	{
		free(d);
		write(1, "Numero incorrecto.\n", 20);
		return (-1);
	}
	else
	{
		if (pos == 1)
			d->num_philos = n;
		if (pos == 2)
			d->time_die = n;
		if (pos == 3)
			d->time_eat = n;
		if (pos == 4)
			d->time_sleep = n;
		if (pos == 5)
			d->philo_eats = n;
		return (n);
	}
}


int	main(int argc, char **argv)
{
	int		i;
	t_list	*d;

	if (argc != 5 && argc != 6)
	{
		write(1, "Numero de argumentos no valido.\n", 33);
		return (0);
	}
	i = 1;
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	while (i != argc)
	{
		if (check_num_arg(argv[i], i, d) < 0)
			return (0);
		i++;
	}
	if (start_simulation(d) != 0)
		return (-1);
	return (0);
}