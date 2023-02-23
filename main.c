/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:42:43 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/22 19:42:43 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo *philo;
	t_mutex	*temp;
	t_mutex	*mutex_t;
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
		philo->id = 1;
		mutex_t->id = 1;
		i = 0;
		while (++i < ft_atoi(argv[1]))
		{
			create_philo(philo);
			create_mutex(mutex_t);
		}
	}
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
	create_thread(philo, mutex_t);
	join_thread(philo);
	return (0);
}
