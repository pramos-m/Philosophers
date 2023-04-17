/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:11:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/17 17:20:38 by pramos-m         ###   ########.fr       */
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

// Error Messages
# define ERRMSG0	(char *)": Invalid number of arguments!\n"
# define ERRMSG1	(char *)": Arguments given are invalid!\n"
# define ERRMSG2	(char *)": There was an error while allocating memory!\n"
# define ERRMSG3	(char *)": There was an error while creating a mutex!\n"
# define ERRMSG4	(char *)": There was an error while destroying a mutex!\n"

typedef struct s_philo
{
	int							num_eats;
	long						last_eat;
	pthread_mutex_t				*fork_l;
	pthread_mutex_t				*fork_r;
	struct s_list				*d;
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

	pthread_t		*tid;
	pthread_mutex_t	pcreate;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	long			s_time;
}	t_list;

void		init_table(t_list *table);
void		init_mutex(t_list *table);
void		start_simulation(t_list *table);
void		*pthread_routine(t_list *table);
void		ft_error_handler(int error, char *strerror);


int			ft_atoi(const char	*str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
size_t		ft_strlen(const	char	*s);

void	print_philo_fork(t_list *table);
void	print_philo_eating(t_list *table);
void	print_philo_sleeping(t_list *table);
void	print_philo_thinking(t_list *table);
void	print_philo_dying(t_list *table);
void    clean_table(t_list *table)

void    clean_table(t_list *table);
int destroy_mutex(t_list *table);
int clean_pthread(t_list *table, pthread_t *tid);

#endif