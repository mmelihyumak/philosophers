/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:14:06 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/05 07:11:57 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_rules *rules, char **argv)
{
	int	i;
	int	ids;

	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->time_to_repeat = ft_atoi(argv[5]);
	rules->start_time = get_time();
	rules->philos = malloc(sizeof(t_philo) * rules->number_of_philo);
	i = -1;
	ids = 1;
	while (++i < rules->number_of_philo)
	{
		rules->philos[i].id = ids++;
		rules->philos[i].rules = rules;
	}
	return (0);
}
