/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:58:28 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/08 06:51:49 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_philo(t_philo *philo, long long wait_time, int flag)
{
	while (get_time() < wait_time)
	{
		if (!death_control(philo->rules, philo->id, flag))
			return (0);
		usleep(50);
	}
	if (flag == 0)
		philo->last_meal = get_time() - philo->rules->start_time;
	return (1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	wait_eating(t_philo *philo, long long wait_time)
{
	while (get_time() < wait_time)
	{
		philo->last_meal = get_time() - philo->rules->start_time;
		if (philo->rules->death == 1)
			return (0);
		usleep(50);
	}
	philo->last_meal = get_time() - philo->rules->start_time;
	return (1);
}

int	print_state(t_philo *philo, char *state, int flag)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("%lld %d %s\n", get_time()
		- philo->rules->start_time, philo->id, state);
	pthread_mutex_unlock(&philo->rules->print_mutex);
	return (1);
}

int	wait_sleeping(t_philo *philo, long long wait_time)
{
	while (get_time() < wait_time)
	{
		if (philo->rules->death == 1)
			return (0);
		usleep(50);
	}
	philo->last_meal = get_time() - philo->rules->start_time;
	return (1);
}
