/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:31:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 17:32:35 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	start_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_create(&info->philo[i].thd, NULL, &routine, \
		&info->philo[i]) != 0)
		{
			go_destroy(info);
			return (printf("ERROR. Cannot create threads\n"), FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	join_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_join(info->philo[i].thd, NULL) != 0)
		{
			go_destroy(info);
			return (printf("ERROR. Cannot join some thread\n"), FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	composing_philo(t_info *info)
{
	int		i;

	i = 0;
	while (info->live_status == LIVE)
	{
		is_dead(&info->philo[i % info->nb_philo]);
		i++;
	}
}

int	main(int ac, char *arg[])
{
	t_info	info;

	if (check_info(arg, ac) == FALSE)
		return (1);
	if (init_info(&info, arg, ac) == FALSE)
		return (1);
	if (init_mutex(&info) == FALSE)
		return (1);
	if (start_thread(&info) == FALSE)
		return (1);
	ft_sleep(4);
	composing_philo(&info);
	if (join_thread(&info) == FALSE)
		return (1);
	go_destroy(&info);
}
