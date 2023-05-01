/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:14:53 by pramos-m          #+#    #+#             */
/*   Updated: 2023/05/01 11:59:23 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

t_times	init_times(char **av, t_list *table)
{
	t_times	times;

	table->num_philos = ft_atoi(av[1]);
	if (ft_atoi(av[2]) == 0)
		ft_error_handler(ERRCODE1, NULL);
	times.t_die = ft_atoi(av[2]);
	times.t_eat = ft_atoi(av[3]);
	times.t_sleep = ft_atoi(av[4]);
	if (av[5])
		times.t_p_eats = ft_atoi(av[5]);
	else
		times.t_p_eats = -1;
	times.t_start = get_time() + table->num_philos * 10;
	return (times);
}

void	init_mutex(t_list *table)
{
	ssize_t	idx;

	idx = -1;
	while (++idx < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[idx], NULL))
		{
			if (pthread_mutex_destroy(table->forks))
				error_director(table, NULL, ERRCODE4, NULL);
			error_director(table, NULL, ERRCODE10, NULL);
		}
	}
	if (pthread_mutex_init(&table->print, NULL))
	{
		if (pthread_mutex_destroy(&table->print))
			error_director(table, NULL, ERRCODE4, NULL);
		error_director(table, NULL, ERRCODE10, NULL);
	}
	if (pthread_mutex_init(&table->pcreate, NULL))
	{
		if (pthread_mutex_destroy(&table->print))
			error_director(table, NULL, ERRCODE4, NULL);
		error_director(table, NULL, ERRCODE10, NULL);
	}
}

void	init_table(t_list *table, t_times *time)
{
	table->times = time;
	table->pcntr = 0;
	table->die = 0;
	table->ecnt = 0;
	table->philo = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philo)
		ft_error_handler(ERRCODE2, NULL);
	table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
	{
		delete((void **)&table->forks);
		ft_error_handler(ERRCODE2, NULL);
	}
}

void	init_philo(t_list *table, t_philo *philo)
{
	++table->pcntr;
	philo->num_eats = 0;
	philo->last_eat = table->times->t_start;
	philo->id = table->pcntr;
	if (philo->id == 1)
		philo->fork_l = &table->forks[table->num_philos - 1];
	else
		philo->fork_l = &table->forks[table->pcntr - 2];
	philo->fork_r = &table->forks[table->pcntr - 1];
	if (pthread_mutex_unlock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
}
