/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/20 11:32:14 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void	start_simulation(t_list *table)
{
	pthread_t	*tid;
	int		count;

	count = -1;
	tid = ft_calloc(table->num_philos, sizeof(pthread_t));
	if (!tid)
		error_director(table, tid, ERRCODE2, NULL);
	table->tid = tid;
	if (pthread_mutex_lock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	while (++count < table->num_philos)
	{
		if (pthread_create(&tid[count], NULL, (void *)pthread_routine,
				(void *)table))
			error_director(table, tid, ERRCODE20, NULL);	
		if (pthread_join(tid[count], NULL))
			error_director(table, tid, ERRCODE20, NULL);
	}
	// do_sleep_cycle(table->pnbr * 2);
	if (pthread_mutex_unlock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	// clean_pthread(table, tid);
}

void	*pthread_routine(t_list *table)
{
	t_philo	*philo;

	philo = &table->philo[table->pcntr];
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
	init_philo(table, philo);
}

void	pthread_messenger(t_list *table, t_philo *philo, int state)
{
	(void) *philo;
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
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
		error_director(table, table->tid, ERRCODE10, NULL);
}
