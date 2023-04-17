/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/17 17:17:13 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void start_simulation(t_list *table)
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
	pthread_mutex_lock(&table->pcreate);
	while (++count < table->num_philos)
	{
		if (pthread_create(&tid[count], NULL, (void *)pthread_routine,
				(void *)table))
			error_director(table, tid, NULL);
		if (pthread_join(tid[count], NULL))
			error_director(table, tid, NULL);
	}
	// do_sleep_cycle(table->pnbr * 2);
	pthread_mutex_unlock(&table->pcreate);
	clean_pthread(&table, &tid);
}

void *pthread_routine(t_list *table)
{
	
}

void	pthread_messenger(t_list *table, t_philo *philo, int state)
{
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, NULL);
	if (state == SEAT)
		print_philo_eating(table);
	else if (state == SFRK)
		print_philo_fork(table);
	else if (state == SSLP)
		print_philo_sleeping(table);
	else if (state == STHK)
		print_philo_thinking(table);
	else if (state == SDIE)
		print_philo_dying(table);
	if (pthread_mutex_unlock(&table->print))
		error_director(table, table->tid, NULL);
}
