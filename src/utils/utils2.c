/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:26:27 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/04 21:48:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int		die_check(t_philo *philo)
{
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->live_status == DIE)
			return(pthread_mutex_unlock(philo->dead_lock), DIE);
		return(pthread_mutex_unlock(philo->dead_lock), LIVE);
}

void	print(t_philo *philo, char *str)
{
	size_t	timestamp;

	timestamp = curr_time() - philo->start_time;
	pthread_mutex_lock(philo->print);
	if (*philo->live_status == LIVE)
		printf("%lu		%d		%s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	is_dead(t_philo *philo)
{
	size_t	time_stamp;
	size_t	curr;

	time_stamp = curr_time() - philo->start_time;
	pthread_mutex_lock(philo->time_lock);
	curr = curr_time() - philo->last_eat;
	pthread_mutex_unlock(philo->time_lock);
	if (curr >= philo->life_time)
	{
		pthread_mutex_lock(philo->print);
		if (*philo->live_status == LIVE)
			printf("%s%lu		%d		died\n", RED, time_stamp, \
			philo->id);
		pthread_mutex_lock(philo->dead_lock);
		*philo->live_status = DIE;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->print);
	}
}

void	ft_sleep(size_t ms)
{
	size_t	start;

	start = curr_time();
	while (curr_time() - start < ms)
	{
		usleep(1);
	}
}
