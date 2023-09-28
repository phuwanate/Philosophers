/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:31:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/09/28 17:40:13 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



int main(int ac, char *av[])
{
    t_info  info;
    
    (void) ac;
    if(check_info(av, &info) == FALSE)
        printf("\nERROR!\n");
    else
        printf("OK\n");
}