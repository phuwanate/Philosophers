/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:28:14 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 22:45:50 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	go_alloc(t_info *info)
{
	info->philo = (t_philo *)ft_calloc(info->nb_philo, sizeof(t_philo));
	if (info->philo == NULL)
		return (FALSE);
	info->forks = (pthread_mutex_t *)ft_calloc(info->nb_philo, \
	sizeof(pthread_mutex_t));
	if (info->forks == NULL)
		return (FALSE);
	return (TRUE);
}

void	go_dealloc(t_info *info)
{
	if (info->philo)
	{
		free(info->philo);
		info->philo = NULL;
	}
	if (info->forks)
	{
		free(info->forks);
		info->forks = NULL;
	}
}

void	go_destroy(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	go_dealloc(info);
}
