/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:31:18 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/05 07:13:08 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	rules->number_of_philo = ft_atoi(argv[1]);
	create_philo(rules, argv);
	create_mutex(rules);
	init_mutexes(rules);
	int i = -1;
	while (++i < rules->number_of_philo)
	{
		printf("left : %p %d\n", rules->philos[i].left_fork, rules->philos[i].id);
		printf("right: %p %d\n", rules->philos[i].right_fork, rules->philos[i].id);
	}
	create_thread(rules);
//	system("leaks philo");
	return (0);
}
