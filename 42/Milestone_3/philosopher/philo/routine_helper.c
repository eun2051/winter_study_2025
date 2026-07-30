/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:21:44 by seungele          #+#    #+#             */
/*   Updated: 2026/07/30 18:53:21 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_one_fork(t_philo *philo, t_fork *fork)
{
	while (1)
	{
		if (check_dead_flag(philo))
			return (1);
		pthread_mutex_lock(&(fork->fork_mutex));
		if (fork->is_taken == 0)
		{
			fork->is_taken = 1;
			pthread_mutex_unlock(&(fork->fork_mutex));
			print_status(philo, "has taken a fork");
			return (0);
		}
		pthread_mutex_unlock(&(fork->fork_mutex));
		usleep(100);
	}
}

int	taking_fork(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->philo_id == philo->info->num_philo)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	if (take_one_fork(philo, first) != 0)
		return (1);
	if (take_one_fork(philo, second) != 0)
	{
		pthread_mutex_lock(&(first->fork_mutex));
		first->is_taken = 0;
		pthread_mutex_unlock(&(first->fork_mutex));
		return (1);
	}
	return (0);
}

void	unlock_fork(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->philo_id == philo->info->num_philo)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	first->is_taken = 0;
	pthread_mutex_unlock(&(first->fork_mutex));
	second->is_taken = 0;
	pthread_mutex_unlock(&(second->fork_mutex));
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
