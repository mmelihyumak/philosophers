/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:59:47 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/21 00:59:47 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_f(void *mut)
{
	//printf("melih\n");
	static int	i;
	int	x;
	t_mutex	*mutex_t;

	mutex_t = mut;
	printf("mutex_t: %p\n", mutex_t);
	pthread_mutex_lock(&mutex_t->mutex);
	x = -1;
	while (++x < 1000000)
		i++;
	printf("%d\n", i);
	pthread_mutex_unlock(&mutex_t->mutex);
	return (0);
}

void	create_thread(t_philo *philo, t_mutex *mutex_t)
{
	t_philo	*temp;

	temp = philo;
	printf("mutex_t: %p\n", mutex_t);
	while (temp)
	{
		pthread_create(&temp->thread_id, NULL, thread_f, (void *) mutex_t);
		temp = temp->next_philo;
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
