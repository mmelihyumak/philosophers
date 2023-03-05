/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 02:58:28 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/05 04:34:57 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_philo(t_philo *philo, long long wait_time, int flag)
{
	pthread_mutex_lock(&philo->rules->death_mutex);
	while (get_time() < wait_time)
	{
		if (!death_control(philo->rules, philo->id, flag))
			return (0);
	}
	if (flag == 0)
		philo->last_meal = get_time() - philo->rules->start_time;
	//usleep(50);
	pthread_mutex_unlock(&philo->rules->death_mutex);
	return (1);
}

long long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
