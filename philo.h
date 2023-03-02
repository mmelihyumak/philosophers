/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:34:07 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/28 05:03:52 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_t		philo_t;
	int				id;
	int				is_alive;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_rules	*rules;
	long long		last_meal;
	pthread_t		dead_t;
	struct s_philo	*next_philo;
}t_philo;

typedef struct	s_rules
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				repeat_lifecycle;
	long long		start_time;
	long long		current_time;
	pthread_mutex_t	is_dead;
	pthread_mutex_t	**forks;
	t_philo			**philos;
}t_rules;

int				ft_atoi(const char *str);
int				create_thread(t_rules *rules);
void			*routine(void *vargp);
t_philo			*find_last_philo(t_philo *philo);
void			link_philos(t_philo *philo, t_rules *rules);
t_philo			**seperate_philos(t_philo *philo, t_rules *rules);
long long		get_time();
void			*death_routine(void *vargp);
int				launch_dead_check(t_rules *rules);
int				wait_function(t_philo *philo, long long wait_time);

#endif
