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
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->left);
	printf("%lld %d has taken a fork\n", rules->current_time, philo->id);
	printf("%lld %d has taken a fork\n", rules->current_time, philo->id);
	philo->last_meal = get_time() - rules->start_time + rules->time_to_eat;
	printf("%lld %d is eating\n", philo->rules->current_time, philo->id);
	if (!wait_function(philo, rules->time_to_eat + get_time()))
	{
		return (0);
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	rules->current_time = get_time() - rules->start_time;
	printf("%lld %d is sleeping\n", philo->rules->current_time, philo->id);
	if (!wait_function(philo, rules->time_to_sleep + get_time()))
		return (0);
	rules->current_time = get_time() - rules->start_time;
	printf("%lld %d is thinking\n", rules->current_time, philo->id);
	return (vargp);
}

int	create_thread(t_rules *rules)
{
	int	i;
	int	l;
	void	**temp;

	i = 0;
	l = 0;
	temp = malloc(sizeof(void *));
	while (1)
	{
		while (i < rules->number_of_philo)
		{
			pthread_create(&rules->philos[i]->philo_t, NULL, &routine, rules->philos[i]);
			i++;
		}
		i = 0;
		while (i < rules->number_of_philo)
		{
			pthread_join(rules->philos[i]->philo_t, temp);
			if (!temp[0])
			{
				return (0);
			}
			i++;
		}
		i = 0;
		l++;
		if (l == rules->repeat_lifecycle)
			break;
	}
	return (1);
}
