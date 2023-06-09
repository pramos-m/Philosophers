/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:12:37 by pramos-m          #+#    #+#             */
/*   Updated: 2023/05/01 12:11:05 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosophers_utils.h"

void	error_director(t_list *table, pthread_t *tid,
		int errcode, char *strerror)
{
	(void) *tid;
	clean_table(table);
	ft_error_handler(errcode, strerror);
}

void	clean_table(t_list *table)
{
	if (destroy_mutex(table))
		ft_error_handler(ERRCODE4, NULL);
	if (table->forks)
		delete((void **)&table->forks);
	if (table->philo)
		delete((void **)&table->philo);
}

int	destroy_mutex(t_list *table)
{
	int	idx;

	idx = -1;
	if (pthread_mutex_destroy(&table->print))
		ft_error_handler(ERRCODE4, NULL);
	if (pthread_mutex_destroy(&table->pcreate))
		ft_error_handler(ERRCODE4, NULL);
	while (++idx < table->num_philos)
		if (pthread_mutex_destroy(&table->forks[idx]))
			ft_error_handler(ERRCODE4, NULL);
	return (0);
}

void	ft_error_handler(int error, char *strerror)
{
	if (error > -1 && !strerror)
	{
		write(STDERR_FILENO, ERRMSG, ft_strlen(ERRMSG));
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERRMSG0, ft_strlen(ERRMSG0));
		else if (error == ERRCODE1)
			write(STDERR_FILENO, ERRMSG1, ft_strlen(ERRMSG1));
		else if (error == ERRCODE2)
			write(STDERR_FILENO, ERRMSG2, ft_strlen(ERRMSG2));
		else if (error == ERRCODE3)
			write(STDERR_FILENO, ERRMSG3, ft_strlen(ERRMSG3));
		else if (error == ERRCODE4)
			write(STDERR_FILENO, ERRMSG4, ft_strlen(ERRMSG4));
		else if (error == ERRCODE5)
			write(STDERR_FILENO, ERRMSG5, ft_strlen(ERRMSG5));
		else if (error == ERRCODE6)
			write(STDERR_FILENO, ERRMSG6, ft_strlen(ERRMSG6));
		else if (error == ERRCODE10)
			write(STDERR_FILENO, ERRMSG10, ft_strlen(ERRMSG10));
		else if (error == ERRCODE20)
			write(STDERR_FILENO, ERRMSG20, ft_strlen(ERRMSG20));
	}
	else if ((!error) && (strerror))
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	exit(EXIT_FAILURE);
}
