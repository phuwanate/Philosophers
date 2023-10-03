/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:44:19 by plertsir          #+#    #+#             */
/*   Updated: 2023/10/03 17:50:12 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (n--)
		ptr[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n;

	n = count * size;
	if (n != count * size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_atol(const char *str)
{
	size_t	result;

	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

void	philo_sleep(t_philo *philo, size_t ms)
{
	size_t	start;
	size_t	dif_time;

	start = curr_time();
	dif_time = 0;
	if (*philo->live_status == DIE)
		return ;
	while (dif_time < ms)
	{
		usleep(1);
		dif_time = curr_time() - start;
	}
}

size_t	curr_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (((t.tv_sec * 1000) + (t.tv_usec / 1000)));
}
