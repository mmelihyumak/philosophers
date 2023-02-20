/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:41:02 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/21 00:41:02 by muyumak          ###   ########.fr       */
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

void	create_philo(t_philo *philo)
{
	t_philo		*temp;

	temp = find_last_philo(philo);
	temp->next_philo = malloc(sizeof(t_philo));
	temp->next_philo->id = temp->id + 1;
}
