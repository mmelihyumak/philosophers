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

	if (argc < 5 || argc > 6)
		return (0);
	rules = malloc(sizeof(t_rules));
	rules->number_of_philo = ft_atoi(argv[1]);
	create_philo(rules, argv);
	create_mutex(rules);
	init_mutexes(rules);
	if (!create_thread(rules))
		return (0);
	return (0);
}
