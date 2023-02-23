/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:26:35 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/23 02:26:35 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_f(void *vargp)
{
	static int	time;
	int	x;
	t_mutex	*mutex_t;

	mutex_t = vargp;
	pthread_mutex_lock(&mutex_t->mutex);
	printf("%d has taken a fork\n", mutex_t->id);
	printf("%d has taken a fork\n", mutex_t->id);
	printf("%d is eating\n", mutex_t->id);
	pthread_mutex_unlock(&mutex_t->mutex);
	printf("%d is sleeping\n", mutex_t->id);
	usleep(mutex_t->time_to_sleep);
	printf("%d is thinking\n", mutex_t->id);
	return (0);
}

void	create_thread(t_philo *philo, t_mutex *mutex_t)
{
	t_philo	*temp_philo;
	t_mutex	*temp_mutex_t;

	temp_philo = philo;
	temp_mutex_t = mutex_t;
	while (temp_philo)
	{
		pthread_create(&temp_philo->thread_id, NULL, &thread_f, (void *) temp_mutex_t);
		temp_philo = temp_philo->next_philo;
		temp_mutex_t = temp_mutex_t->next_mutex;
		usleep(mutex_t->time_to_eat);
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
