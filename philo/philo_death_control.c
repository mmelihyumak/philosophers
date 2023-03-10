/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:20:49 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/10 20:21:12 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_control(t_rules *rules, int id, int flag)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philo)
		if (!control(rules, id, flag, i))
			return (0);
	return (1);
}

int	control(t_rules *rules, int id, int flag, int i)
{
	if (flag == 0 && !rules->philos[i].is_eating)
	{
		if (id != i + 1 && get_time() - rules->start_time
			- rules->philos[i].last_meal > rules->time_to_die)
		{
			rules->philos[i].is_dead = 1;
			pthread_mutex_destroy(rules->death_mutex);
			pthread_mutex_destroy(&rules->print_mutex);
			print_state(&rules->philos[i], "is died", 1);
			return (0);
		}
	}
	else if (flag == 1 && !rules->philos[i].is_eating)
	{
		if (get_time() - rules->start_time - rules->philos[i].last_meal
			> rules->time_to_die)
		{
			rules->philos[i].is_dead = 1;
			pthread_mutex_destroy(rules->death_mutex);
			pthread_mutex_destroy(&rules->print_mutex);
			print_state(&rules->philos[i], "is died", 1);
			return (0);
		}
	}
	return (1);
}
