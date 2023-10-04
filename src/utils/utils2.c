/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:26:27 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/04 15:26:19 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	life_status(t_philo *philo)
{
	pthread_mutex_lock(philo->status);
	if (*philo->live_status == LIVE)
		return (pthread_mutex_unlock(philo->status), LIVE);
	return (pthread_mutex_unlock(philo->status), DIE);
}

size_t	timestamp(size_t start_time)
{
	return (curr_time() - start_time);
}

void	print(t_philo *philo, char *str, char *col)
{
	pthread_mutex_lock(philo->print);
	if (life_status(philo) == LIVE)
		printf("%s%lu		%d		%s\n", col, timestamp(philo->start_time), \
		philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	is_dead(t_philo *philo)
{
	if (die_time(philo) == DIE)
	{
		pthread_mutex_lock(philo->print);
		if (life_status(philo) == LIVE)
		{
			printf("%s%lu		%d		died\n", RED, \
			timestamp(philo->start_time), philo->id);
			pthread_mutex_lock(philo->status);
			*philo->live_status = DIE;
			pthread_mutex_unlock(philo->status);
		}
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
