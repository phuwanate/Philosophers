/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:11:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/04 14:12:51 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	go_eat(t_philo *philo)
{
	if (life_status(philo) == DIE)
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
	print(philo, "has taken a fork", YEL);
	print(philo, "is eating", GRN);
	pthread_mutex_lock(philo->last_eat_lock);
	philo->last_eat = curr_time();
	pthread_mutex_unlock(philo->last_eat_lock);
	philo_sleep(philo, philo->eat_time);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	go_sleep(t_philo *philo)
{
	print(philo, "is sleeping", BLU);
	philo_sleep(philo, philo->sleep_time);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(10);
		// philo_sleep(philo, 1);
	pthread_mutex_lock(philo->last_eat_lock);
	philo->last_eat = curr_time();
	pthread_mutex_unlock(philo->last_eat_lock);
	while (life_status(philo) == LIVE)
	{
		while (philo->nb_philo == 1 && life_status(philo) == LIVE)
			philo_sleep(philo, philo->life_time);
		go_eat(philo);
		philo->count++;
		if (philo->count == philo->meal_count)
			break ;
		go_sleep(philo);
		print(philo, "is thinking", YEL);
	}
	return (0);
}
