/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:17:54 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/28 17:38:43 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_isdigit(char *av, unsigned int nb_av)
{
	unsigned int	i;

	i = -1;
	while(av[++i])
	{	
		if(!(av[i] >= '0' && av[i] <= '9'))
        {
            printf("Argument[%d]: \"%s\" is not digit.\n", nb_av, av);
			return (FALSE);
        }
    }
	return (TRUE);
}

int out_of_int(char *av, unsigned int nb_av)
{
    
    if(ft_long_atoi(av) < INT_MIN || ft_long_atoi(av) > INT_MAX)
    {
        printf("Argument[%d]: \"%s\" is out of integer range.\n", nb_av, av);
        return (FALSE);
    }
    return (TRUE);
}