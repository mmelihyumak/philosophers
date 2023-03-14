/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:24:14 by melih             #+#    #+#             */
/*   Updated: 2023/03/15 00:49:32 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_eating(t_philo *philo, long long w_time)
{
	t_rules	*rules;
	t_philo	*dead_philo;

	rules = philo->rules;
	while (get_time() <= w_time)
	{
		if (rules->is_dead == 1)
		{
			return (1);
		}
	}
	return (0);
}