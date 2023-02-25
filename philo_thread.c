/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:26:35 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/25 03:43:26 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_f(void *vargp)
{
	t_philmut	*philmut;

	philmut = vargp;
	pthread_mutex_lock(&philmut->mutex->mutex);
	printf("%d has taken a fork\n", philmut->temp_philo->id);
	pthread_mutex_unlock(&philmut->mutex->mutex);
	printf("%d has taken a fork\n", philmut->temp_philo->id);
	printf("%d is eating\n", philmut->temp_philo->id);
	usleep(philmut->mutex->time_to_sleep * 1000);
	printf("%d is sleeping\n", philmut->temp_philo->id);
	usleep(philmut->mutex->time_to_sleep * 1000);
	printf("%d is thinking\n", philmut->temp_philo->id);
	return (0);
}

void	create_thread(t_philmut *philmut)
{
	t_philo	*temp_philo;
	t_mutex	*temp_mutex_t;

	philmut->temp_philo = philmut->philo;
	philmut->temp_mutex = philmut->mutex;
	while (philmut->mutex->time_to_repeat-- >0)
	{
		while (philmut->temp_philo)
		{
			pthread_create(&philmut->temp_philo->thread_id, NULL, &thread_f, philmut);
			usleep(500);
			philmut->temp_philo = philmut->temp_philo->next_philo;
			philmut->temp_mutex = philmut->temp_mutex->next_mutex;
		}
		philmut->temp_philo = philmut->philo;
		philmut->temp_mutex = philmut->mutex;
	}
}

void	join_thread(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (temp)
	{
		pthread_join(temp->thread_id, NULL);
		temp = temp->next_philo;
	}
}
