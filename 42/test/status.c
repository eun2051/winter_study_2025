/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:41:08 by seungele          #+#    #+#             */
/*   Updated: 2026/07/28 14:06:47 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time()
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	return (time);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&(philo->info->print_lock));
	if (check_dead_flag(philo))
	{
		pthread_mutex_unlock(&(philo->info->print_lock));
		return ;
	}
	printf("%lld %d %s\n", get_time() - philo->info->now_time, philo->philo_id, status);
	pthread_mutex_unlock(&(philo->info->print_lock));
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
