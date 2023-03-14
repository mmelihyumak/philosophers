/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:31:51 by melih             #+#    #+#             */
/*   Updated: 2023/03/15 00:59:11 by melih            ###   ########.fr       */
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
	int id;
	int	eat_count;
	int	lm;
	int	is_eating;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t   thread_id;
	struct s_rules  *rules;
}t_philo;

typedef struct s_rules
{
	int np;
	int td;
	int te;
	int ts;
	int	tr;
	int	is_dead;
	long long   st;
	pthread_t	death_thread_id;
	pthread_mutex_t *forks;
	pthread_mutex_t	dcm;
	t_philo *philos;
}t_rules;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	check_numbers(int argc, char **argv);
int	check_zero(char **argv);
int fill_rules(t_rules *rules, char **argv);
int	fill_philos(t_rules *rules);
long long	get_time(void);
int	create_thread(t_rules *rules);
void	*routine(void *vargp);
void	*death_routine(void *vargp);
int	set_forks(t_rules *rules);
int	eating(t_philo *philo, t_rules *rules);
int	launch(t_rules *rules);
int	create_death_thread(t_rules *rules);
int	wait_eating(t_philo *philo, long long w_time);
int	wait_sleeping(t_philo *philo, long long w_time);
int	join_death_thread(t_rules *rules);
int	detach_threads(t_rules *rules);
int	control_eating_count(t_rules *rules);

#endif