/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:28:03 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/10 19:25:08 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	philo->is_eating = 1;
	print_state(philo, "has taken a fork", 0);
	print_state(philo, "has taken a fork", 0);
	print_state(philo, "is eating", 0);
	philo->count_eat++;
	if (rules->checking_death == 0)
	{
		rules->checking_death = 1;
		if (!wait_philo(philo, rules->time_to_eat + get_time(), 0))
		{
			rules->death = 1;
			return (0);
		}
		rules->checking_death = 0;
	}
	else
		if (!wait_eating(philo, rules->time_to_sleep + get_time()))
			return (0);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	control_eating_count(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philo)
	{
		if (rules->philos[i].count_eat != rules->time_to_repeat)
			break;
		else if (rules->philos[i].count_eat == rules->time_to_repeat && check_all_philos(rules))
			return (0);
	}
	return (1);
}

int	check_all_philos(t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (++i < rules->number_of_philo)
	{
		if (rules->philos[0].count_eat == rules->philos[i].count_eat)
			j++;
	}
	if (j == rules->number_of_philo)
		return (1);
	return (0);
}
