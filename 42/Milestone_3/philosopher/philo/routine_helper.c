/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:21:44 by seungele          #+#    #+#             */
/*   Updated: 2026/07/29 15:28:58 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_fork(t_philo *philo)
{
	if (philo->philo_id == philo->info->num_philo)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		if (check_dead_flag(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		if (check_dead_flag(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

void	unlock_fork(t_philo *philo)
{
	if (philo->philo_id == philo->info->num_philo)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	thinking_time(t_philo *philo)
{
	long long	think_time;
	t_check		*cur;

	think_time = 0;
	cur = philo->info;
	if (cur->num_philo % 2 != 0)
	{
		think_time = (cur->time_to_eat * 2) - cur->time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		ft_sleep(think_time);
	}
}
