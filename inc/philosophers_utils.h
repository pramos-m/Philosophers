/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:05:44 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/12 17:41:32 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_UTILS_H
# define PHILOSOPHERS_UTILS_H

# include "philosophers.h"

//	End of color
# define ENDCLR		(char *)"\033[0;39m"

//	White searator
# define WHITE		(char *)"\033[1;89m"

//	T time of the message - Background color red
# define BKGDRED	(char *)"\033[7;1;91m"

//	X philosopher of the message - Background color cyan
# define BKGDCYAN	(char *)"\033[7;1;96m"

//	Messages colors
# define MAGENT	(char *)"\033[1;98m"
# define BLUE	(char *)"\033[1;94m"
# define GREEN	(char *)"\033[1;92m"
# define YELLOW	(char *)"\033[1;93m"
# define RED	(char *)"\033[1;91m"

//	Messages
# define FRK	(char *)"[ 🍴  ] - Philosopher has taken a fork.\n"
# define EAT	(char *)"[ 🥣  ] - Philosopher is eating.\n"
# define SLP	(char *)"[ 💤  ] - Philosopher is sleeping.\n"
# define THK	(char *)"[ 💭  ] - Philosopher is philosophing.\n"
# define DIE	(char *)"[ 🏳️   ] - Philosopher has refused to exist.\n"

//	Messages states
# define SDIE	(int)0
# define SFRK	(int)1
# define SEAT	(int)2
# define SSLP	(int)3
# define STHK	(int)4

//	Philosophers Messages
// void	print_philo_fork(t_table *table);
// void	print_philo_eating(t_table *table);
// void	print_philo_sleeping(t_table *table);
// void	print_philo_thinking(t_table *table);
// void	print_philo_dying(t_table *table);
void    clean_table(t_list *table);
void    delete(void **dlt);
int     destroy_mutex(t_list *table);
int clean_pthread(t_list *table, pthread_t *tid);

#endif