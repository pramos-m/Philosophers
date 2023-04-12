/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:30:47 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/12 17:42:07 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void    clean_table(t_list *table)
{
	if (destroy_mutex(table))
		ft_error_handler(ERRCODE4, NULL);
	if (table->forks)
		delete((void **)&table->forks);
	if (table->philo)
		delete((void **)&table->philo);
}

int destroy_mutex(t_list *table)
{
	ssize_t	idx;

	idx = -1;
	while (++idx < table->num_philos)
		if (pthread_mutex_destroy(&table->forks[idx]))
			return (0);
	if (pthread_mutex_destroy(&table->print))
		return (0);
	return (1);
}

int clean_pthread(t_list *table, pthread_t *tid)
{
	ssize_t	idx;

	if (!tid)
		return 0;
	idx = -1;
	while (++idx < table->num_philos)
	{
		if (pthread_detach(tid[idx]))
		    ft_error_handler(ERRCODE4, NULL);
	}
    return (1);
}

void	delete(void **dlt)
{
	free(*dlt);
	*dlt = NULL;
}
