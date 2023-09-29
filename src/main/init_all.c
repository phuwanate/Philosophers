/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:36:17 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/29 21:33:44 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (printf("mutex failed!\n"), FALSE);
		i++;
	}
	return (TRUE);
}

int	init_info(t_info *info, char **av, int ac)
{
	info->nb_philo = ft_atol(av[1]);
	info->life_time = ft_atol(av[2]);
	info->eat_time = ft_atol(av[3]);
	info->sleep_time = ft_atol(av[4]);
	info->live_status = LIVE;
	if (ac == 6)
		info->meal_count = ft_atol(av[5]);
	else
		info->meal_count = 0;
	if (go_alloc(info) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].life_time = info->life_time;
		info->philo[i].eat_time = info->eat_time;
		info->philo[i].sleep_time = info->sleep_time;
		info->philo[i].meal_count = info->meal_count;
		info->philo[i].live_status = &info->live_status;
		if (info->nb_philo == 1)
		{
			info->philo[i].l_fork = NULL;
			info->philo[i].r_fork = NULL;
		}
		else
		{
			info->philo[i].l_fork = &info->forks[i];
			info->philo[i].r_fork = &info->forks[(i + 1) % info->nb_philo];
		}
		i++;
	}
}


