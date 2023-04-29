/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:11:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/28 13:08:01 by pramos-m         ###   ########.fr       */
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

# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2
# define ERRCODE3	(int)3
# define ERRCODE4	(int)4
# define ERRCODE5	(int)5
# define ERRCODE6	(int)6
# define ERRCODE10	(int)10
# define ERRCODE20	(int)20

// Error Messages
# define ERRMSG		(char *)"\aError"
# define ERRMSG0	(char *)": Invalid arguments!\n"
# define ERRMSG1	(char *)": Arguments given are invalid!\n"
# define ERRMSG2	(char *)": There was an error while allocating memory!\n"
# define ERRMSG3	(char *)": There was an error while creating a mutex!\n"
# define ERRMSG4	(char *)": There was an error while destroying a mutex!\n"
# define ERRMSG5	(char *)": There was an error while creating a phtread!\n"
# define ERRMSG6	(char *)": There was an error while destroying a phtread!\n"
# define ERRMSG10	(char *)": There was a mutex error!\n"
# define ERRMSG20	(char *)": There was a phtread error!\n"

typedef struct s_times	t_times;
typedef struct s_philo	t_philo;
typedef struct s_list	t_list;

// ============================================================================
//
//	t_times	-> struct containing the times for the philosophers
//
/*
 *		t_start	-> start time of a philosopher
 *		t_eat	-> time to eat
 *		t_sleep	-> time to sleep
 *		t_die	-> time to die
 *		t_times	-> how many times are required to eat
*/
typedef struct s_times
{
	long long	t_start;
	long long	t_eat;
	long long	t_sleep;
	long long	t_die;
	long long	t_p_eats;
}	t_times;

typedef struct s_philo
{
	int							id;
	int							num_eats;
	long						last_eat;
	pthread_mutex_t				*fork_l;
	pthread_mutex_t				*fork_r;
	struct t_list				*d;
}	t_philo;

typedef struct s_list
{
	int				state;
	int				num_philos;
	int				pcntr;
	int				ecnt;
	int				die;

	t_philo			*philo;
	pthread_t		*thread;

	pthread_t		*tid;
	pthread_mutex_t	pcreate;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_times			*times;
}	t_list;

int			check_arg(int ac, char **av);
t_times		init_times(char **av, t_list *table);
void		init_table(t_list *table, t_times *time);
void		init_mutex(t_list *table);
void		init_philo(t_list *table, t_philo *philo);
void		start_simulation(t_list *table);
void		pthread_routine(t_list *table);
int			eat_routine(t_list *table, t_philo *philo);
int			check_eating(t_list *table, t_philo *philo);
void		philo_check_iterator(t_list *table);
void		do_sleep_cycle(long long time);
void		print_die(t_list *table, t_philo *philo);

void		error_director(t_list *table, pthread_t *tid,
				int errcode, char *strerror);
void		ft_error_handler(int error, char *strerror);
void		delete(void **dlt);
int			destroy_mutex(t_list *table);
void		clean_table(t_list *table);

#endif