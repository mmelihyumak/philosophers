/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:27:57 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/21 00:27:57 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	t_philo *philo;
	t_philo	*temp;
	t_mutex	*mutex_t;
	int	i;

	ms_time();
	if (argc < 2)
		exit(0);
	if (ft_atoi(argv[1]) > 0)
	{
		philo = malloc(sizeof(t_philo));
		philo->id = 1;
		i = 0;
		while (++i < ft_atoi(argv[1]))
			create_philo(philo);
	}
	mutex_t = malloc(sizeof(t_mutex));
	temp = philo;
	/*while (temp)
	{
		printf("id: %d\n", temp->id);
		temp = temp->next_philo;
	}*/
	pthread_mutex_init(&mutex_t->mutex, NULL);
	create_thread(philo, mutex_t);
	join_thread(philo);
	return (0);
}
