/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:40:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 22:39:44 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_isdigit(char *arg)
{
	unsigned int	i;

	i = -1;
	if (arg[0] == '\0')
		return (FALSE);
	while (arg[++i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
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

int	check_info(char **arg, unsigned int ac)
{
	unsigned int	i;

	i = 1;
	if (check_size(ac) == FALSE)
		return (FALSE);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == FALSE)
		{
			printf("Argument[%d]: \"%s\" is not digit.\n", i, arg[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
