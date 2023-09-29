/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:31:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/29 21:13:39 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int ac, char *av[])
{
	t_info	info;

	if (check_info(av, ac) == FALSE)
		return (printf("\nERROR!\n"), 1);
	if (init_info(&info, av, ac) == FALSE)
	{
		go_dealloc(&info);
		return (printf("ERROR\n"), 1);
	}
	init_philo(&info);
	if (init_mutex(&info) == FALSE)
	{
		go_destroy(&info);
		return (printf("ERROR\n"), 1);
	}
	go_destroy(&info);
}
