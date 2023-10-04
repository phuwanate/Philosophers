/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:11:34 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/04 18:55:02 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	go_eat(t_philo *philo)
{
	if (die_check(philo) == DIE)
		return ;
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork", YEL);
	print(philo, "is eating", GRN);
	usleep(1);
	pthread_mutex_lock(philo->time_lock);
	philo->last_eat = curr_time();
	pthread_mutex_unlock(philo->time_lock);
	philo->count++;
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
		philo_sleep(philo, 1);
	while (philo->nb_philo == 1 && *philo->live_status == LIVE)
			philo_sleep(philo, philo->life_time);
	//while (*philo->live_status == LIVE)
	while (die_check(philo) == LIVE)
	{
		go_eat(philo);
		if (philo->count == philo->meal_count)
			break;
		go_sleep(philo);
		print(philo, "is thinking", YEL);
	}
	return (0);
}
