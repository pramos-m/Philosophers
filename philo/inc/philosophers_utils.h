/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:05:44 by pramos-m          #+#    #+#             */
/*   Updated: 2023/05/01 11:44:15 by pramos-m         ###   ########.fr       */
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
void		pthread_messenger(t_list *table, t_philo *philo, int state);
void		print_philo_fork(t_list *table);
void		print_philo_eating(t_list *table);
void		print_philo_sleeping(t_list *table);
void		print_philo_thinking(t_list *table);
void		print_philo_dying(t_list *table);
void		print_die(t_list *table, t_philo *philo);

// Philosophers Parsing
int			ft_atoi(const char	*str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
size_t		ft_strlen(const	char	*s);
int			ft_check_isdigit(int params, char **str);
int			ft_while_is_digit(char *num);
int			ft_is_int(char *num);
size_t		ft_strlen(const	char	*s);
int			ft_check_maxint(long long nbr);
char		*ft_strchr(const char *s, int c);
void		*ft_memchr(const void *s, int c, size_t n);

#endif
