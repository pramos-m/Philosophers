/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/12 12:51:30 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_mutex(t_list *table)
{
  	ssize_t	idx;

    idx = -1;
	start_simulation(table);
    while (++idx < table->num_philos)
    {
        if (pthread_mutex_init(&table->forks[idx], NULL))
		{
			if (pthread_mutex_destroy(table->forks))
				ft_error_handler(ERRCODE4, NULL);
			ft_error_handler(ERRCODE3, NULL);
		}
    }
    if (pthread_mutex_init(&table->print, NULL))
	{
		if (pthread_mutex_destroy(&table->print))
			ft_error_handler(ERRCODE4, NULL);
		ft_error_handler(ERRCODE3, NULL);
	}
	if (pthread_mutex_init(&table->pcreate, NULL))
	{
		if (pthread_mutex_destroy(&table->pcreate))
			ft_error_handler(ERRCODE4, NULL);
		ft_error_handler(ERRCODE3, NULL);
	}
}

void start_simulation(t_list *table)
{
    // int tmp;

    table->philo = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philo)
		ft_error_handler(ERRCODE2, NULL);
    table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		ft_error_handler(ERRCODE2, NULL);
    // tmp = 0;
    // while (table->philo && tmp < table->num_philos)
    // {
    //     if (table->)
    //     table->philo[table->num_philos].num_eats = 0;
    //     table->philo[table->num_philos].last_eat = 0;
    //     table->philo[table->num_philos].fork_l
	// 		= table->forks[table->num_philos - 1];
    //     table->philo[table->num_philos].fork_r
	// 		= table->forks[table->num_philos - 2];
    // }
    
}

void	init_philo(t_list *table, t_philo *philo)
{
	++table->num_philos;
	philo->num_eats = 0;
	philo->last_eat = 0;
	if (table->num_philos == 1)
		philo->fork_l = &table->forks[table->num_philos - 1];
	else
		philo->fork_l = &table->forks[table->num_philos - 2];
	philo->fork_r = &table->forks[table->num_philos - 1];
	if (pthread_mutex_unlock(&table->print))
		ft_error_handler(ERRCODE3, NULL);
}
