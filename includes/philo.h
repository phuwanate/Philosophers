/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:06:10 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/05 18:56:47 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE   1
# define FALSE  0
# define LIVE	1
# define DIE	0
# define RED  "\x1B[31m"

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	is_full_lock;
	int				nb_philo;
	int				philo_full_count;
	size_t			start_time;
	long			life_time;
	long			eat_time;
	long			sleep_time;
	long			meal_count;
	int				live_status;
	struct s_philo	*philo;
}			t_info;

typedef struct s_philo
{
	pthread_t		thd;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*time_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*is_full_lock;
	int				id;
	int				nb_philo;
	size_t			start_time;
	long			life_time;
	long			eat_time;
	long			sleep_time;
	long			last_eat;
	long			meal_count;
	long			count;
	int				*live_status;
}			t_philo;

int		ft_isdigit(char *arg);
int		check_info(char **arg, unsigned int ac);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		go_alloc(t_info *info);
void	go_dealloc(t_info *info);
int		init_info(t_info *info, char **arg, int ac);
int		init_mutex(t_info *info);
void	go_destroy(t_info *info);
void	*routine(void *arg);
void	philo_sleep(t_philo *philo, size_t ms);
void	ft_sleep(size_t ms);
long	curr_time(void);
void	print(t_philo *philo, char *str);
void	is_dead(t_philo *philo);
int		die_check(t_philo *philo);
int		out_of_long(char **arg, int ac);
int		is_full(t_philo *philo);

#endif
