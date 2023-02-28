/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:01:01 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/28 03:32:40 by muyumak          ###   ########.fr       */
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

void	link_philos(t_philo *philo, t_rules *rules)
{
	t_philo	*temp;
	t_philo	*last_philo;
	int		i;

	i = 0;
	temp = philo;
	while (i < rules->number_of_philo - 1)
	{
		last_philo = find_last_philo(philo);
		last_philo->next_philo = malloc(sizeof(t_philo));
		last_philo->next_philo->id = last_philo->id + 1;
		i++;
	}
}

t_philo	**seperate_philos(t_philo *philo, t_rules *rules)
{
	t_philo	**philos;
	t_philo	*temp;
	int		i;

	temp = philo;
	philos = malloc(sizeof(t_philo *) * rules->number_of_philo);
	i = 0;
	while (temp)
	{
		philos[i] = temp;
		temp = temp->next_philo;
		philos[i]->rules = rules;
		i++;
	}
	return (philos);
}