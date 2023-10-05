/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:04 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/05 18:44:52 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int is_full(t_philo *philo)
{
    pthread_mutex_lock(philo->is_full_lock);
	if (philo->count == philo->meal_count)
        return (pthread_mutex_unlock(philo->is_full_lock), TRUE);
    return (pthread_mutex_unlock(philo->is_full_lock), FALSE);
}