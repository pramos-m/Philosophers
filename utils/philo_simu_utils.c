/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simu_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:53:08 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/24 11:08:02 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void	do_sleep_cycle(long long time)
{
	time = get_time() + time;
	while (time > get_time())
		usleep(200);
}

void	eat_routine(t_list *table, t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork_l))
		error_director(table, table->tid, ERRCODE10, NULL);
	pthread_messenger(table, philo, SFRK);
	if (pthread_mutex_lock(philo->fork_r))
		error_director(table, table->tid, ERRCODE10, NULL);
	pthread_messenger(table, philo, SFRK);
	philo->last_eat = get_time();
	pthread_messenger(table, philo, SEAT);
	do_sleep_cycle(table->times->t_eat);
	if (pthread_mutex_unlock(philo->fork_l))
		error_director(table, table->tid, ERRCODE10, NULL);
	if (pthread_mutex_unlock(philo->fork_r))
		error_director(table, table->tid, ERRCODE10, NULL);
	philo->num_eats++;
}

void	philo_check_iterator(t_list *table)
{
	int	idx;

	idx = 0;
	do_sleep_cycle(15);
	while (!table->die && table->ecnt != table->num_philos)
	{
		if (table->ecnt == table->num_philos)
			break ;
		if ((get_time() - table->philo[idx].last_eat) >= table->times->t_die)
		{
			table->die = 1;
			print_die(table, &table->philo[idx]);
		}
		if (idx == table->pcntr)
			idx = 0;
		do_sleep_cycle(15);
		if (table->philo[idx].num_eats == table->times->t_p_eats)
			table->ecnt++;
	}
}

void	print_die(t_list *table, t_philo *philo)
{
	if (pthread_mutex_lock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
	if (printf("\t%s[ %06lld ]%s%s |%s %s[ %05d ]%s%s | %s", \
	BKGDRED, (get_time() - table->times->t_start), \
	ENDCLR, WHITE, ENDCLR, BKGDCYAN, philo->id, \
	ENDCLR, WHITE, ENDCLR) < 0)
		table->state = 1;
	print_philo_dying(table);
	if (pthread_mutex_unlock(&table->print))
		error_director(table, table->tid, ERRCODE10, NULL);
}

int	check_eating(t_list *table, t_philo *philo)
{
	if (table->times->t_p_eats == -1)
		return (0);
	if (philo->num_eats == table->times->t_p_eats)
		return (1);
	return (0);
}
