/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/11 15:12:25 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_mutex(t_list *table)
{
  	ssize_t	idx;
    
    idx = -1;
    while (++idx < table->num_philos)
    {
        if (pthread_mutex_init(&table->forks[idx], NULL))
		{
			if (pthread_mutex_destroy(table->forks))
				error_messenger(ERRCODE4);
			error_messenger(ERRCODE3);
		}
    }
    if (pthread_mutex_init(&table->print, NULL))
	{
		if (pthread_mutex_destroy(&table->print))
			error_messenger(ERRCODE4);
		error_messenger(ERRCODE3);
	}
	if (pthread_mutex_init(&table->pcreate, NULL))
	{
		if (pthread_mutex_destroy(&table->pcreate))
			error_messenger(ERRCODE4);
		error_messenger(ERRCODE3);
	}
    
}

int start_simulation(t_list *table)
{
    int tmp;

    table->philo = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philo)
		error_messenger(ERRCODE2);
    table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		error_messenger(ERRCODE2);
    tmp = 0;
    while (table->philo && tmp < table->num_philos)
    {
        if (table->)
        table->philo[table->num_philos].num_eats = 0;
        table->philo[table->num_philos].last_eat = 0;
        table->philo[table->num_philos].fork_l = table->forks[table->num_philos - 1];
        table->philo[table->num_philos].fork_r = table->forks[table->num_philos - 2];
    }
    
}

int start_philo(t_list *table)
{
    while (table->num_philos)
    {
        table->philo[table->num_philos].num_eats = 0;
        table->philo[table->num_philos].last_eat = 0;
        table->philo[table->num_philos].fork_l = table->forks[table->num_philos - 1];
        table->philo[table->num_philos].fork_r = table->forks[table->num_philos - 2];
        
    }
}

void	ft_error_handler(int error, char *strerror)
{
	if (!strerror && error)
	{
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	}
	else if ((!error) && (strerror))
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	else if ((!error) && (!strerror))
		perror("Error! ");
	exit(EXIT_FAILURE);
}
