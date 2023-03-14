/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 06:19:37 by melih             #+#    #+#             */
/*   Updated: 2023/03/15 00:59:36 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *vargp)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *) vargp;
	rules = philo->rules;
	while (1)
	{
		pthread_mutex_lock(philo->right);
		printf("%lld %d has taken a fork\n", get_time() - rules->st, philo->id);
		pthread_mutex_lock(philo->left);
		printf("%lld %d has taken a fork\n", get_time() - rules->st, philo->id);
		printf("%lld %d is eating\n", get_time() - rules->st, philo->id);
		philo->lm = get_time() - rules->st + rules->te;
		if (wait_eating(philo, get_time() + rules->te))
			break;
		philo->eat_count++;
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		if (philo->eat_count == rules->tr)
			break;
		printf("%lld %d is sleeping\n", get_time() - rules->st, philo->id);
		if (wait_eating(philo, get_time() + rules->ts))
			break;
		printf("%lld %d is thinking\n", get_time() - rules->st, philo->id);
	}
	return (NULL);
}

int	launch(t_rules *rules)
{
	rules->st = get_time();
	pthread_create(&rules->death_thread_id, NULL, &death_routine, (void *) rules);
	if (create_thread(rules))
		return (1);
	pthread_join(rules->death_thread_id, NULL);
	return (0);
}

int	create_thread(t_rules *rules)
{
	int	i;
	
	i = -1;
	while (++i < rules->np)
	{
		pthread_create(&rules->philos[i].thread_id, NULL, &routine, (void *) &rules->philos[i]);
		usleep(50);
	}
	return (0);
}

int	detach_threads(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->np)
	{
		pthread_join(rules->philos[i].thread_id, NULL);
	}
	return (0);
}

int	eating(t_philo *philo, t_rules *rules)
{
	return (0);
}

int	control_eating_count(t_rules *rules)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < rules->np)
	{
		if (rules->philos[i].eat_count == rules->tr)
			count++;
	}
	if (count == rules->np)
		return (1);
	return (0);
}

void	*death_routine(void *vargp)
{
	t_rules	*rules;
	int	i;
	
	rules = (t_rules *) vargp;
	while (1)
	{
		i = -1;
		if (control_eating_count(rules) == 1)
			break;
		while (++i < rules->np)
		{
			if (get_time() - rules->st - rules->philos[i].lm > rules->td)
			{
				rules->is_dead = 1;
				printf("%lld %d is died\n", get_time() - rules->st, rules->philos[i].id);
				return (&rules->philos[i]);
			}
		}
		usleep(500);
	}
	return (NULL);
}
