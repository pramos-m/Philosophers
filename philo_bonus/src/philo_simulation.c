/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:40:42 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/28 13:08:37 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void	start_simulation(t_list *table)
{
	pthread_t	*tid;
	int			count;

	count = -1;
	tid = ft_calloc(table->num_philos, sizeof(pthread_t));
	if (!tid)
		error_director(table, tid, ERRCODE2, NULL);
	table->tid = tid;
	if (pthread_mutex_lock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	while (++count < table->num_philos)
	{
		table->tid[count] = fork();
		pthread_routine(table);
	}
	table->times->t_start = get_time();
	if (pthread_mutex_unlock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	count = -1;
	philo_check_iterator(table);
	while (++count < table->num_philos)
		if (pthread_join(tid[count], NULL))
			error_director(table, tid, ERRCODE20, NULL);
}

void	pthread_routine(t_list *table)
{
	t_philo	*philo;

	if (pthread_mutex_lock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	if (pthread_mutex_unlock(&table->pcreate))
		error_director(table, table->tid, ERRCODE10, NULL);
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
	philo = &table->philo[table->pcntr];
	init_philo(table, philo);
	if (!(philo->id % 2))
		do_sleep_cycle(1 * table->num_philos / 2);
	while (!table->die)
	{
		if (philo->num_eats == table->times->t_p_eats)
			break ;
		if (eat_routine(table, philo) == -1)
			break ;
		pthread_messenger(table, philo, SSLP);
		do_sleep_cycle(table->times->t_sleep);
		pthread_messenger(table, philo, STHK);
	}
}

void	pthread_messenger(t_list *table, t_philo *philo, int state)
{
	(void) *philo;
	if (!table->die)
	{
		if (philo->num_eats == table->times->t_p_eats)
			return ;
		if (pthread_mutex_lock(&table->print))
			error_director(table, table->tid, ERRCODE10, NULL);
		if (!table->die)
		{
			printf("\t%s[ %06lld ]%s%s |%s %s[ %05d ]%s%s | %s",
				BKGDRED, (get_time() - table->times->t_start),
				ENDCLR, WHITE, ENDCLR,
				BKGDCYAN, philo->id, ENDCLR, WHITE, ENDCLR);
			if (state == SEAT)
				print_philo_eating(table);
			else if (state == SFRK)
				print_philo_fork(table);
			else if (state == SSLP)
				print_philo_sleeping(table);
			else if (state == STHK)
				print_philo_thinking(table);
		}
		if (pthread_mutex_unlock(&table->print))
			error_director(table, table->tid, ERRCODE10, NULL);
	}
}
