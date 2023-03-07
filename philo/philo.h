/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:31:48 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/07 07:11:02 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	long long		last_meal;
	int				id;
	int				is_eating;
	int				is_dead;
	struct s_rules	*rules;
}t_philo;

typedef	struct  s_rules
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	int				time_to_repeat;
	int				checking_death;
	int				death;
	int				death_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}t_rules;


int			ft_atoi(const char *str);
int			create_philo(t_rules *rules, char **argv);
int			create_mutex(t_rules *rules);
int			create_thread(t_rules *rules);
int			init_mutexes(t_rules *rules);
void		*routine(void *vargp);
long long	get_time();
int			death_control(t_rules *rules, int id, int flag);
int			wait_philo(t_philo *philo, long long wait_time, int flag);
int			check_numbers(char **argv);
int			ft_isdigit(int c);
int			check_zero(char **argv);
int			wait_eating(t_philo *philo, long long wait_time);
int			wait_sleeping(t_philo *philo, long long wait_time);
int			print_state(t_philo *philo, char *state, int flag);

#endif
