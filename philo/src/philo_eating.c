/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:17:48 by pramos-m          #+#    #+#             */
/*   Updated: 2023/05/02 17:56:06 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

int	eat_routine(t_list *table, t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork_l))
		error_director(table, table->tid, ERRCODE10, NULL);
	pthread_messenger(table, philo, SFRK);
	if (philo->fork_l == philo->fork_r)
		return (-1);
	if (pthread_mutex_lock(philo->fork_r))
		error_director(table, table->tid, ERRCODE10, NULL);
	pthread_messenger(table, philo, SFRK);
	pthread_messenger(table, philo, SEAT);
	philo->last_eat = get_time();
	do_sleep_cycle(table->times->t_eat);
	if (pthread_mutex_unlock(philo->fork_l))
		error_director(table, table->tid, ERRCODE10, NULL);
	if (pthread_mutex_unlock(philo->fork_r))
		error_director(table, table->tid, ERRCODE10, NULL);
	philo->num_eats++;
	return (0);
}

void	philo_check_iterator(t_list *table)
{
	int	idx;
	
	idx = 0;
	
	printf("Entro en philo_check_iterator: %lld", get_time() -  table->times->t_start);
	do_sleep_cycle(2);
	
	while (!table->die && table->ecnt != table->num_philos)
	{
		if (table->ecnt == table->num_philos)
			break ;
		if (table->philo[idx].num_eats == table->times->t_p_eats)
		{
			printf("Do sleep!\n");
			do_sleep_cycle(1);
			table->ecnt++;
		}
		if (idx == table->pcntr)
		{
			printf("Index 0\n");
			idx = 0;
		}
		// printf("Check die for: %d, last eat %ld, time to die %lld\n", idx,table->philo[idx].last_eat, table->times->t_die );
		// printf("LAst eat is: %ld Current time: %lld\n", table->philo[idx].last_eat, get_time());
		// printf("Last eat: %lld, time to die: %lld\n", (get_time() - table->philo[idx].last_eat) , table->times->t_die);
		if (get_time() - table->times->t_start >= get_time() - table->philo[idx].last_eat + table->times->t_die)
		{
			printf("Muerete pesao!!!!, %lld\n", get_time() -  table->times->t_start);
			// printf("time: %lld", get_time() - table->times->t_start );
			table->die = 1;
			print_die(table, &table->philo[idx]);
			break ;
		}
	}
}

void	print_die(t_list *table, t_philo *philo)
{
	// printf("Call print die :last eat %ld, time to die %lld\n", philo->last_eat, table->times->t_die );
	// printf("time: %lld", get_time() - table->times->t_start );
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
		if (printf("\t%s[ %06lld ]%s%s |%s %s[ %05d ]%s%s | %s", \
	BKGDRED, (get_time() - table->times->t_start), \
	ENDCLR, WHITE, ENDCLR, BKGDCYAN, philo->id, \
	ENDCLR, WHITE, ENDCLR) < 0)
		table->state = 1;
	// printf("%s%s%s", RED, DIE, ENDCLR);
	print_philo_dying(table);
	// if (pthread_mutex_unlock(&table->print))
	// 	error_director(table, table->tid, ERRCODE10, NULL);
}

int	check_eating(t_list *table, t_philo *philo)
{
	if (table->times->t_p_eats == -1)
		return (0);
	if (philo->num_eats == table->times->t_p_eats)
		return (1);
	return (0);
}

void	do_sleep_cycle(long long time)
{
	time = get_time() + time;
	while (time >= get_time())
		usleep(100);
}
