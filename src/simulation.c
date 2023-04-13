/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/13 19:56:25 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_mutex(t_list *table)
{
  	ssize_t	idx;

    idx = -1;
	// start_simulation(table);
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
}

void init_table(t_list *table)
{
    table->philo = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philo)
		ft_error_handler(ERRCODE2, NULL);
    table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		ft_error_handler(ERRCODE2, NULL);
	if (!table->philo_eats)
		table->philo_eats = 1;
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

int simulation(t_list *table)
{
	pthread_t	tmp;
	pthread_t	*tid;
	size_t		count;

	count = -1;
	tmp = 0;
	tid = ft_calloc(table->num_philos, sizeof(pthread_t));
	if (!tid)
		error_director(table, NULL, ERRCODE2);
	table->tid = tid;
	if (!table->philo_eats)
		return (0);
	pthread_mutex_lock(&table->pcreate);
	while (++count < table->num_philos)
	{
		if (pthread_create(&tid[count], NULL, (void *)pthread_routine,
				(void *)table))
			error_director(table, tid, ERRCODE5);
	}
}

void	pthread_iteration(t_list *table)
{
	
}