/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/29 18:18:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static unsigned int	check_size(unsigned int size)
{
	if (size == 1)
	{
		printf("Please give some arguments to the Philo program.\n");
		return (FALSE);
	}
	else if (size > 6)
	{
		printf("Number of arguments should not exceed 5.\n");
		printf("\n\"[nb_of_philosophers] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] [nb_of_meals]\"\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	av_len(char **av)
{
	unsigned int	i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	if (check_size(i) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_info(char **av)
{
	unsigned int	i;

	i = 1;
	if (av_len(av) == FALSE)
	{
		return (FALSE);
	}
	while (av[i])
	{
		if (ft_isdigit(av[i], i) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
