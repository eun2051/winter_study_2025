/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:40:39 by seungele          #+#    #+#             */
/*   Updated: 2026/07/29 15:59:50 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_philo *philo, t_check *checker)
{
	int		i;
	t_philo	*curr;

	i = 0;
	checker->now_time = get_time();
	while (i < checker->num_philo)
	{
		pthread_mutex_lock(&(philo[i].meal_lock));
		philo[i].last_meal_time = checker->now_time;
		pthread_mutex_unlock(&(philo[i].meal_lock));
		i++;
	}
	i = 0;
	while (i < checker->num_philo)
	{
		curr = &philo[i];
		pthread_create(&curr->philo_thread, NULL, philo_routine, curr);
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*ptr;

	ptr = (t_philo *)arg;
	if (ptr->info->num_philo == 1)
	{
		pthread_mutex_lock(ptr->left_fork);
		print_status(ptr, "has taken a fork");
		while (check_dead_flag(ptr) == 0)
			usleep(100);
		pthread_mutex_unlock(ptr->left_fork);
		return (NULL);
	}
	if ((ptr->philo_id) % 2 == 0)
		ft_sleep(ptr->info->time_to_eat / 2);
	while (1)
	{
		if (check_dead_flag(ptr))
			break ;
		philo_action(ptr);
	}
	pthread_exit(NULL);
}

void	philo_action(t_philo *philo)
{
	if (check_dead_flag(philo))
		return ;
	taking_fork(philo);
	print_status(philo, "is eating");
	pthread_mutex_lock(&(philo->meal_lock));
	philo->last_meal_time = get_time();
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->meal_lock));
	ft_sleep(philo->info->time_to_eat);
	unlock_fork(philo);
	if (check_dead_flag(philo))
		return ;
	print_status(philo, "is sleeping");
	ft_sleep(philo->info->time_to_sleep);
	print_status(philo, "is thinking");
	thinking_time(philo);
}

void	check_dead(t_philo *philo, t_check *checker)
{
	int	i;
	int	full_cnt;
	int	num;

	num = checker->num_philo_eat;
	while (1)
	{
		i = 0;
		full_cnt = 0;
		while (i < checker->num_philo)
		{
			if (time_dead(i, philo, checker) == 1)
				return ;
			if (num > 0 && philo[i].eat_cnt >= num)
				full_cnt++;
			pthread_mutex_unlock(&(philo[i].meal_lock));
			i++;
		}
		if (count_check(full_cnt, checker) == 1)
			return ;
		usleep(1000);
	}
}
