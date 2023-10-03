/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:11:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 17:36:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	go_eat(t_philo *philo)
{
	if (philo->live_status == DIE)
		return ;
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork");
	print(philo, "is eating");
	philo->last_eat = curr_time();
	philo->count++;
	philo_sleep(philo, philo->eat_time);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	go_sleep(t_philo *philo)
{
	print(philo, "is sleeping");
	philo_sleep(philo, philo->sleep_time);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		philo_sleep(philo, 3);
	while (*philo->live_status == LIVE)
	{
		go_eat(philo);
		if (philo->count == philo->meal_count)
			return (0);
		go_sleep(philo);
		print(philo, "is thinking");
	}
	return (0);
}
