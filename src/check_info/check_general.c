/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/29 21:29:50 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_isdigit(char *av)
{
	unsigned int	i;

	i = -1;
	if (av[0] == '\0')
		return (FALSE);
	while (av[++i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (FALSE);
	}
	return (TRUE);
}

static unsigned int	check_size(unsigned int size)
{
	if (size < 5)
	{
		printf("The arguments should be like....");
		printf("\n\"[nb_of_philosophers] [time_to_die] [time_to_eat) ");
		printf("[time_to_sleep] [nb_of_meals (optional)]\"\n");
		return (FALSE);
	}
	else if (size > 6)
	{
		printf("Number of arguments should not exceed 5.\n");
		printf("\n\"[nb_of_philosophers] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] [nb_of_meals (optional)]\"\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_info(char **av, unsigned int ac)
{
	unsigned int	i;

	i = 1;
	if (check_size(ac) == FALSE)
		return (FALSE);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == FALSE)
		{
			printf("Argument[%d]: \"%s\" is not digit.\n", i, av[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
