/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:36:17 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/05 10:03:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	init_mutex2(t_info *info)
{
	if (pthread_mutex_init(&info->dead_lock, NULL) != 0)
	{
		go_destroy(info);
		return (printf("%smutex failed!\n", RED), FALSE);
	}
	if (pthread_mutex_init(&info->time_lock, NULL) != 0)
	{
		go_destroy(info);
		return (printf("%smutex failed!\n", RED), FALSE);
	}
	return (TRUE);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			go_destroy(info);
			return (printf("%smutex failed!\n", RED), FALSE);
		}
		i++;
	}
	if (pthread_mutex_init(&info->print, NULL) != 0)
	{
		go_destroy(info);
		return (printf("%smutex failed!\n", RED), FALSE);
	}
	if (init_mutex2(info) == FALSE)
		return (FALSE);
	return (TRUE);
}

static void	init_fork(t_info *info, int i)
{
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
}

static void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].nb_philo = info->nb_philo;
		info->philo[i].start_time = info->start_time;
		info->philo[i].life_time = info->life_time;
		info->philo[i].eat_time = info->eat_time;
		info->philo[i].sleep_time = info->sleep_time;
		info->philo[i].meal_count = info->meal_count;
		info->philo[i].last_eat = curr_time();
		info->philo[i].count = 0;
		info->philo[i].live_status = &info->live_status;
		info->philo[i].print = &info->print;
		info->philo[i].dead_lock = &info->dead_lock;
		info->philo[i].time_lock = &info->time_lock;
		init_fork(info, i);
		i++;
	}
}

int	init_info(t_info *info, char **arg, int ac)
{
	if (out_of_long(arg, ac) == FALSE)
		return (FALSE);
	info->nb_philo = ft_atol(arg[1]);
	info->life_time = ft_atol(arg[2]);
	info->eat_time = ft_atol(arg[3]);
	info->sleep_time = ft_atol(arg[4]);
	info->start_time = curr_time();
	info->live_status = LIVE;
	if (ac == 6)
		info->meal_count = ft_atol(arg[5]);
	else
		info->meal_count = -1;
	if (go_alloc(info) == FALSE)
	{
		go_dealloc(info);
		return (printf("%sERROR. Cannot initial the info struct.\n", RED) \
		, FALSE);
	}
	init_philo(info);
	return (TRUE);
}
