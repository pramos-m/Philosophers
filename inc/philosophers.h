/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:11:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/07 22:12:56 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<stdio.h>
# include<fcntl.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct s_philo
{
	int				num_eats;
	long			last_eat;
	int				fork_l;
	int				fork_r;
	struct s_list	*d;
}	t_philo;

typedef struct s_list
{
	int				init_philo;
	int				stat;
	int				id;
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				philo_eats;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_stat;
	pthread_mutex_t	mutex_i;
	pthread_mutex_t	mutex_msg;
	pthread_mutex_t	mutex_fork;
	long			s_time;
}	t_list;