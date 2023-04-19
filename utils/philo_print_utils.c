/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:21:16 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/19 12:46:30 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_utils.h>
#include <philosophers.h>

void
	print_philo_fork(t_list *table)
{
	if (printf("%s%s%s", MAGENT, FRK, ENDCLR) < 0)
		table->state = 1;
}

void
	print_philo_eating(t_list *table)
{
	if (printf("%s%s%s", GREEN, EAT, ENDCLR) < 0)
		table->state = 1;
}

void
	print_philo_sleeping(t_list *table)
{
	if (printf("%s%s%s", BLUE, SLP, ENDCLR) < 0)
		table->state = 1;
}

void
	print_philo_thinking(t_list *table)
{
	if (printf("%s%s%s", YELLOW, THK, ENDCLR) < 0)
		table->state = 1;
}

void
	print_philo_dying(t_list *table)
{
	if (printf("%s%s%s", RED, DIE, ENDCLR) < 0)
		table->state = 1;
}