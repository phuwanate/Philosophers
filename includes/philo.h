/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:06:10 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/29 19:47:12 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE   1
# define FALSE  0
# define LIVE	1
# define DIE	0

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
	pthread_mutex_t	*forks;
	int				nb_philo;
	size_t			life_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			meal_count;
	int				live_status;
	struct s_philo	*philo;
}			t_info;

typedef struct s_philo
{
	pthread_t		t_philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				id;
	size_t			life_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			last_eat;
	size_t			meal_count;
	int				*live_status;
}			t_philo;

int		ft_isdigit(char *av, unsigned int nb_av);
int		check_info(char **av);
int		out_of_int(char *av, unsigned int nb_av);
size_t	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		go_alloc(t_info *info);
void	go_dealloc(t_info *info);
int		init_info(t_info *info, char **av, int ac);
void	init_philo(t_info *info);
int		init_mutex(t_info *info);
void	go_destroy(t_info *info);

#endif
