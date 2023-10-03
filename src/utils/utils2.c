/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:26:27 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 21:44:37 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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

	time_stamp = curr_time() - philo->start_time;
	if (curr_time() - philo->last_eat >= philo->life_time)
	{
		pthread_mutex_lock(philo->print);
		if (*philo->live_status == LIVE)
			printf("%lu		%d		died\n", time_stamp, \
			philo->id);
		*philo->live_status = DIE;
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
