/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:47:29 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/28 05:07:08 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *vargp)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = vargp;
	rules = philo->rules;
	rules->current_time = get_time() - rules->start_time;
	if (rules->current_time - philo->last_meal > rules->time_to_die + 10)
	{
		printf("%lld %d died\n", rules->current_time, philo->id);
		philo->is_dead = 1;
	}
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->left);
	printf("%lld %d has taken a fork\n", rules->current_time, philo->id);
	printf("%lld %d has taken a fork\n", rules->current_time, philo->id);
	printf("%lld %d is eating\n", philo->rules->current_time, philo->id);
	usleep(rules->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	rules->current_time = get_time() - rules->start_time;
	philo->last_meal = rules->current_time;
	printf("%lld %d is sleeping\n", philo->rules->current_time, philo->id);
	usleep(rules->time_to_sleep * 1000);
	rules->current_time = get_time() - rules->start_time;
	printf("%lld %d is thinking\n", rules->current_time, philo->id);
	return (0);
}

void	create_thread(t_rules *rules)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (1)
	{
		while (i < rules->number_of_philo)
		{
			pthread_create(&rules->philos[i]->philo_t, NULL, &routine, rules->philos[i]);
			if (rules->philos[i]->is_dead)
				break;
			i++;
		}
		i = 0;
		while (i < rules->number_of_philo)
		{
			pthread_join(rules->philos[i]->philo_t, NULL);
			i++;
		}
		i = 0;
		l++;
		if (l == rules->repeat_lifecycle)
			break;
	}
}