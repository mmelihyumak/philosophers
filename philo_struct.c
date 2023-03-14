/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:55:13 by melih             #+#    #+#             */
/*   Updated: 2023/03/14 21:11:53 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int fill_rules(t_rules *rules, char **argv)
{
	rules->np = ft_atoi(argv[1]);
	rules->td = ft_atoi(argv[2]);
	rules->te = ft_atoi(argv[3]);
	rules->ts = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		rules->tr = ft_atoi(argv[5]);
	else
		rules->tr = -1;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->np);
	rules->philos = malloc(sizeof(t_philo) * rules->np);
	rules->is_dead = 0;
	pthread_mutex_init(&rules->dcm, NULL);
	fill_philos(rules);
	//set_forks(rules);
	return (0);
}

int	fill_philos(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->np)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].rules = rules;
		rules->philos[i].right = &rules->forks[i];
		rules->philos[i].left = &rules->forks[(i + 1) % (rules->np)];
		pthread_mutex_init(&rules->forks[i], NULL);
	}
	return (0);
}

int	set_forks(t_rules *rules)
{
	int	i;

	/*i = -1;
	while (++i < rules->np)
	{
		rules->philos[i].right = &rules->forks[i];
		rules->philos[i].left = &rules->forks[(i + 1) % (rules->np)];
		pthread_mutex_init(&rules->forks[i], NULL);
		pthread_mutex_init(&rules->philos[i].dcm, NULL);
	}*/
	return (0);
}