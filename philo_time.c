/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:19:44 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/28 04:52:03 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_function(t_philo *philo, long long wait_time)
{
	int	i;
	int	time;

	i = 0;
	pthread_mutex_lock(&philo->rules->is_dead);
	while (get_time() < wait_time)
	{
		if (i < philo->rules->number_of_philo)
		{
			if (!death_routine(philo->rules->philos[i]))
			{
				return (0);
			}
		}
		usleep(50);
		i++;
	}
	pthread_mutex_unlock(&philo->rules->is_dead);
	return (1);
}

long long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
