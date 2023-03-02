/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:44:12 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/01 02:44:12 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_routine(void *vargp)
{
	t_philo	*philo;
	t_rules	*rules;
	int	i;

	philo = vargp;
	rules = philo->rules;
	i = 0;
		if (get_time() - rules->start_time - philo->last_meal > rules->time_to_die)
		{
			printf("%lld %d->died\n", get_time() - rules->start_time, philo->id);
			return (0);
		}
		i++;
	//printf("%lld %d-> ölüm kontrol devrede\n", time - philo->rules->start_time, philo->id);
	/*if (time - philo->rules->start_time - philo->last_meal > rules->time_to_die)
	{
		printf("%lld %d died\n", time - rules->start_time, philo->id);
	}*/
	return (vargp);
}

/*int	launch_dead_check(t_rules *rules)
{
	int	i;
	int	l;
	void	**temp;

	i = 0;
	l = 0;
	temp = malloc(sizeof(void *));
	while (i < rules->number_of_philo)
	{
		pthread_create(&rules->philos[i]->dead_t, NULL, &death_routine, rules->philos[i]);
		pthread_join(rules->philos[i]->dead_t, temp);
		if (!temp[0])
		{
			return (0);
		}
		i++;
	}
	return (1);
}*/

