/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/10 16:56:27 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int start_simulation(t_list *table)
{
    table->philo = ft_calloc(table->num_philos, sizeof(t_philo));
	if (!table->philo)
		error_messenger(ERRCODE2);
    table->forks = ft_calloc(table->num_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		error_messenger(ERRCODE2);
    
}

int start_philo(t_list *table)
{
    while (table->num_philos)
    {
        table->philo[table->num_philos].num_eats = 0;
        table->philo[table->num_philos].last_eat = 0;
        
    }
}