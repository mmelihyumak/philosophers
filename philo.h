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
	int				id;
	struct s_philo	*next_philo;
}t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				id;
	int				time_to_repeat;
	struct s_mutex	*next_mutex;
}t_mutex;

typedef struct s_philmut
{
	t_mutex	*mutex;
	t_philo	*philo;
	t_mutex	*temp_mutex;
	t_philo	*temp_philo;
}t_philmut;

t_philo	*find_last_philo(t_philo *philo);
t_mutex	*find_last_mutex(t_mutex *mutex);
void	create_philo(t_philo *philo);
void	create_mutex(t_mutex *mutex);
int		ft_atoi(const char *str);
void	create_thread(t_philmut *philmut);
void	*thread_f(void *philmut);
void	join_thread(t_philo *philo);
long	ms_time();

#endif
