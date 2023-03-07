/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:31:18 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/07 00:40:10 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	if (!check_numbers(argv) || !check_zero(argv))
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) == 0)
	{
		printf("Invalid argument\n");
		return (0);
	}
	rules = malloc(sizeof(t_rules));
	rules->number_of_philo = ft_atoi(argv[1]);
	create_philo(rules, argv);
	if (!create_thread(rules))
	{
		i = -1;
		while (++i < rules->number_of_philo)
			pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(rules->death_mutex);
		return (0);
	}
	return (0);
}
