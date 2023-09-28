#ifndef PHILO_H
# define PHILO_H

# define TRUE   1
# define FALSE  0

#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_info
{
    int     nb_philo;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    int     nb_of_meal;
}   t_info;

int     ft_isdigit(char *av, unsigned int nb_av);
int     check_info(char **av, t_info *info);
int     out_of_int(char *av, unsigned int nb_av);
long	ft_long_atoi(const char *str);

#endif
