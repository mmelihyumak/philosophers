/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:14:06 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/10 20:37:14 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_rules *rules, char **argv)
{
	int	i;
	int	ids;

	rules->checking_death = 0;
	rules->death = 0;
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->time_to_repeat = ft_atoi(argv[5]);
	else if (!argv[5])
		rules->time_to_repeat = -1;
	rules->start_time = get_time();
	rules->philos = malloc(sizeof(t_philo) * rules->number_of_philo);
	i = -1;
	ids = 1;
	while (++i < rules->number_of_philo)
	{
		rules->philos[i].id = ids++;
		rules->philos[i].is_dead = 0;
		rules->philos[i].count_eat = 0;
		rules->philos[i].rules = rules;
	}
	return (0);
}
