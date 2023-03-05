/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:13:52 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/05 07:12:30 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *vargp)
{
	t_philo	*philo;
	t_rules	*rules;
	
	philo = (t_philo *) vargp;
	rules = philo->rules;
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("%lld %d has taken a fork\n", get_time() - rules->start_time, philo->id);
	printf("%lld %d has taken a fork\n", get_time() - rules->start_time, philo->id);
	printf("%lld %d is eating\n", get_time() - philo->rules->start_time, philo->id);
	usleep(rules->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%lld %d is sleeping\n", get_time() - rules->start_time, philo->id);
	usleep(rules->time_to_sleep * 1000);
	printf("%lld %d is thinking\n", get_time() - rules->start_time, philo->id);
	return (vargp);
}

int	create_thread(t_rules *rules)
{
	int	i;
	void	*take_returned;

	i = -1;
	while (++i < rules->number_of_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
	}
	i = -1;
	while (++i < rules->number_of_philo)
	{
		pthread_create(&rules->philos[i].thread_id, NULL, &routine, (void *) &rules->philos[i]);
	}
	i = -1;
	while (++i < rules->number_of_philo)
	{
		pthread_join(rules->philos[i].thread_id, &take_returned);
	}
	return (0);
}
