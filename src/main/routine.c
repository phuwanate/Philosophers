/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:11:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/05 18:55:48 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	go_eat(t_philo *philo)
{
	if (die_check(philo) == DIE)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	print(philo, "has taken a fork");
	print(philo, "is eating");
	pthread_mutex_lock(philo->time_lock);
	philo->last_eat = curr_time();
	pthread_mutex_unlock(philo->time_lock);
	pthread_mutex_lock(philo->is_full_lock);
	philo->count++;
	pthread_mutex_unlock(philo->is_full_lock);
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
		philo_sleep(philo, 1);
	while (philo->nb_philo == 1 && die_check(philo) == LIVE)
		philo_sleep(philo, philo->life_time);
	while (die_check(philo) == LIVE)
	{
		go_eat(philo);
		if (philo->count == philo->meal_count)
			break;
		go_sleep(philo);
		print(philo, "is thinking");
	}
	return (0);
}
