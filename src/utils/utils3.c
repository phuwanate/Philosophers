/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:27:26 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/04 12:42:11 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	die_time(t_philo *philo)
{
	pthread_mutex_lock(philo->last_eat_lock);
	if (curr_time() - philo->last_eat >= philo->life_time)
		return (pthread_mutex_unlock(philo->last_eat_lock), DIE);
	return (pthread_mutex_unlock(philo->last_eat_lock), LIVE);
}
