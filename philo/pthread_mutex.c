/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:32:02 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/10 20:38:36 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_rules *rules)
{
	int	i;

	i = -1;
	rules->forks = malloc(sizeof(pthread_mutex_t) * (rules->number_of_philo));
	rules->death_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(rules->death_mutex, NULL);
	pthread_mutex_init(&rules->print_mutex, NULL);
	return (0);
}

int	init_mutexes(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philo)
	{
		rules->philos[i].right_fork = &rules->forks[i];
		rules->philos[i].left_fork = &rules->forks[(i + 1)
			% (rules->number_of_philo)];
	}
	return (0);
}
