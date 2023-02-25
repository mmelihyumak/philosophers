/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:42:43 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/25 00:28:21 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_mutex		*temp;
	t_mutex		*mutex_t;
	t_philmut	*philmut;
	int	i;

	ms_time();
	if (argc < 5 || argc > 6)
		exit(0);
	if (ft_atoi(argv[1]) > 0)
	{
		philo = malloc(sizeof(t_philo));
		mutex_t = malloc(sizeof(t_mutex));
		mutex_t->time_to_die = ft_atoi(argv[2]);
		mutex_t->time_to_eat = ft_atoi(argv[3]);
		mutex_t->time_to_sleep = ft_atoi(argv[4]);
		mutex_t->time_to_repeat = ft_atoi(argv[5]);
		philo->id = 1;
		mutex_t->id = 1;
		i = 0;
		while (++i < ft_atoi(argv[1]))
		{
			create_philo(philo);
			create_mutex(mutex_t);
		}
	}
	philmut = malloc(sizeof(t_philmut));
	philmut->mutex = mutex_t;
	philmut->philo = philo;
	temp = mutex_t;
	/*while (temp)
	{
		printf("id: %d\n", temp->id);
		temp = temp->next_philo;
	}*/
	while (temp)
	{
		pthread_mutex_init(&temp->mutex, NULL);
		temp = temp->next_mutex;
	}
	create_thread(philmut);
	join_thread(philo);
	return (0);
}
