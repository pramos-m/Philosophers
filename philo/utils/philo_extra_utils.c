/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_extra_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:26:47 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/25 13:17:00 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_utils.h>
#include <philosophers.h>

void	delete(void **dlt)
{
	free(*dlt);
	*dlt = NULL;
}

long long	get_time(void)
{
	struct timeval	t_time;
	long long		tme;

	gettimeofday(&t_time, 0);
	tme = (t_time.tv_sec * 1000) + (t_time.tv_usec / 1000);
	return (tme);
}
