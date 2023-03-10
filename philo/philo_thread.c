/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:13:52 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/10 20:42:20 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *vargp)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *) vargp;
	rules = philo->rules;
	if (!eating(philo))
		return (NULL);
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

	k = 0;
	create_mutex(rules);
	init_mutexes(rules);
	i = -1;
	while (++i < rules->number_of_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
	while (1)
	{
		if (!launch(rules))
			return (0);
		usleep(50);
		k++;
		if (k == rules->time_to_repeat)
			break ;
	}
	return (1);
}

int	launch(t_rules *rules)
{
	int		i;
	void	*retrieve;

	i = -1;
	while (++i < rules->number_of_philo)
	{
		pthread_create(&rules->philos[i].thread_id, NULL, &routine,
			(void *) &rules->philos[i]);
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
	}
	return (1);
}
