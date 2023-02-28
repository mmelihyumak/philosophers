/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:34:00 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/28 04:11:11 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	*philo, *temp;
	int		i;
	
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	philo = malloc(sizeof(t_philo));
	philo->id = 1;
	rules = malloc(sizeof(t_rules));
	rules->number_of_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->repeat_lifecycle = ft_atoi(argv[5]);
	rules->forks = malloc(sizeof(pthread_mutex_t *) * rules->number_of_philo);
	link_philos(philo, rules);
	/*int i = 3;
	while (i-- > 0)
	{
		printf("%d\n", temp->id);
		temp = temp->next_philo;
	}*/
	rules->philos = seperate_philos(philo, rules);
	i = 0;
	while (i < rules->number_of_philo)
	{
		rules->forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(rules->forks[i], NULL);
		
		i++;
	}
	i = 0;
	while (i < rules->number_of_philo)
	{
		
		rules->philos[i]->right = rules->forks[i];
		if (i != rules->number_of_philo - 1)
			rules->philos[i]->left = rules->forks[i + 1];
		else
			rules->philos[i]->left = rules->forks[0];
		i++;
	}
	rules->start_time = get_time();
	/*int	i = 0;
	while (rules->philos[i])
	{
		printf("%d\n", rules->philos[i]->id);
		i++;
	}*/
	//printf("||||||||||||||||||||||||||\n");
	create_thread(rules);
	//system("leaks philo");
	return (0);
}