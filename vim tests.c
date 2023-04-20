/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:26:01 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/20 11:28:24 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Test para comprovar el orden de las forks

// void	init_philo(t_list *table, t_philo *philo)
// {
// 	++table->pcntr;
// 	philo->num_eats = 0;
// 	philo->last_eat = 0;
// 	philo->id = table->pcntr;
// 	if (philo->id == 1){
// 		philo->fork_l = &table->forks[table->num_philos - 1];
// 		printf("philosopher id: %i \n lfork: %i \n rfork : %i\n\n", philo->id, table->num_philos - 1, table->pcntr - 1);
// 		}
// 	else
// 		philo->fork_l = &table->forks[table->pcntr - 2];
// 	philo->fork_r = &table->forks[table->pcntr - 1];
// 	printf("philosopher id: %i \n lfork: %i \n rfork : %i\n\n", philo->id, table->pcntr - 2, table->pcntr - 1);
// 	if (pthread_mutex_unlock(&table->print))
// 		error_director(table, table->tid, ERRCODE10, NULL);
// }