/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:13:52 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/07 07:14:49 by muyumak          ###   ########.fr       */
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
	print_state(philo, "has taken a fork", 0);
	print_state(philo, "has taken a fork", 0);
	print_state(philo, "is eating", 0);
	if (rules->checking_death == 0)
	{
		rules->checking_death = 1;
		if (!wait_philo(philo, rules->time_to_eat + get_time(), 0))
		{
			rules->death = 1;
			return (NULL);
		}
		rules->checking_death = 0;
	}
	else
		if (!wait_eating(philo, rules->time_to_sleep + get_time()))
			return (0);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_state(philo, "is sleeping", 0);
	if (rules->checking_death == 0)
	{
		rules->checking_death = 1;
		if (!wait_philo(philo, rules->time_to_sleep + get_time(), 1))
		{
			rules->death = 1;
			return (NULL);
		}
		rules->checking_death = 0;
	}
	else
		if (!wait_sleeping(philo, rules->time_to_sleep + get_time()))
			return (0);
	print_state(philo, "is thinking", 0);
	return (vargp);
}

int	create_thread(t_rules *rules)
{
	int	i;
	int	k;
	void	*retrieve;

	k = 0;
	create_mutex(rules);
	init_mutexes(rules);
	i = -1;
	while (++i < rules->number_of_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
	while (1)
	{
		i = -1;
		while (++i < rules->number_of_philo)
		{
			pthread_create(&rules->philos[i].thread_id, NULL, &routine, (void *) &rules->philos[i]);
			usleep(100);
		}
		i = -1;
		while (++i < rules->number_of_philo)
		{
			pthread_join(rules->philos[i].thread_id, &retrieve);
			if (!retrieve)
			{
				i = -1; 
				while (++i < rules->number_of_philo)
					pthread_detach(rules->philos[i].thread_id);
				return (0);
			}
			usleep(100);
		}
		i = 0;
		k++;
		if (k == rules->time_to_repeat)
			break;
	}
	return (1);
}
