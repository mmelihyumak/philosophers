/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:28:08 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/21 00:28:08 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread_id;
	struct s_philo	*next_philo;
	int				id;
}t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
}t_mutex;

t_philo	*find_last_philo(t_philo *philo);
void	create_philo(t_philo *philo);
int		ft_atoi(const char *str);
void	create_thread(t_philo *philo, t_mutex *mutex_t);
void	*thread_f(void *mut);
void	join_thread(t_philo *philo);
long	ms_time();

#endif
