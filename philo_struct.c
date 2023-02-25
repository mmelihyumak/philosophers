/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:26:56 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/24 22:16:14 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*find_last_philo(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (temp->next_philo)
		temp = temp->next_philo;
	return (temp);
}

t_mutex	*find_last_mutex(t_mutex *mutex)
{
	t_mutex	*temp;

	temp = mutex;
	while (temp->next_mutex)
		temp = temp->next_mutex;
	return (temp);
}

void	create_philo(t_philo *philo)
{
	t_philo		*temp;

	temp = find_last_philo(philo);
	temp->next_philo = malloc(sizeof(t_philo));
	temp->next_philo->id = temp->id + 1;
}

void	create_mutex(t_mutex *mutex)
{
	t_mutex		*temp;

	temp = find_last_mutex(mutex);
	temp->next_mutex = malloc(sizeof(t_mutex));
	temp->next_mutex->id = temp->id + 1;
	temp->next_mutex->time_to_die = temp->time_to_die;
	temp->next_mutex->time_to_eat = temp->time_to_eat;
	temp->next_mutex->time_to_sleep = temp->time_to_sleep;
	temp->next_mutex->time_to_repeat = temp->time_to_repeat;
}
