/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:41:08 by seungele          #+#    #+#             */
/*   Updated: 2026/07/29 17:26:10 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	return (time);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time;

	time = 0;
	pthread_mutex_lock(&(philo->info->print_lock));
	if (check_dead_flag(philo))
	{
		pthread_mutex_unlock(&(philo->info->print_lock));
		return ;
	}
	time = get_time() - philo->info->now_time;
	print_util(time, philo->philo_id, status);
	pthread_mutex_unlock(&(philo->info->print_lock));
}

void	print_util(long long time, int philo_id, char *status)
{
	size_t	len;

	len = ft_strlen(status);
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo_id, 1);
	write(1, " ", 1);
	write(1, status, len);
	write(1, "\n", 1);
}

void	ft_sleep(long long wait_time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < wait_time)
		usleep(100);
}

int	check_dead_flag(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&(philo->info->dead_lock));
	flag = philo->info->is_dead;
	pthread_mutex_unlock(&(philo->info->dead_lock));
	return (flag);
}
