/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:20:49 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/05 19:20:49 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_control(t_rules *rules, int id, int flag)
{
	int	i;

	//pthread_mutex_lock(&rules->death_mutex);
	i = -1;
	while (++i < rules->number_of_philo)
	{
		if (flag == 0 && !rules->philos[i].is_eating)
		{
			if (id != i + 1 && get_time() - rules->start_time - rules->philos[i].last_meal > rules->time_to_die)
			{
				printf("%lld %d is died\n", get_time() - rules->start_time, rules->philos[i].id);
				i = -1;
				while (++i < rules->number_of_philo)
					pthread_detach(rules->philos[i].thread_id);
				return (0);
			}
		}
		else if (flag == 1 && !rules->philos[i].is_eating)
		{
			if (get_time() - rules->start_time - rules->philos[i].last_meal > rules->time_to_die)
			{
				printf("%lld %d is died\n", get_time() - rules->start_time, rules->philos[i].id);
				i = -1;
				while (++i < rules->number_of_philo)
					pthread_detach(rules->philos[i].thread_id);
				return (0);
			}
		}
	}
	//pthread_mutex_unlock(&rules->death_mutex);
	return (1);
}
