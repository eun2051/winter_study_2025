/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:30:21 by seungele          #+#    #+#             */
/*   Updated: 2026/06/29 10:06:11 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_routine(t_check *checker)
{
	int		i;

	i = 0;
	checker->now_time = get_time();
	while (i < checker->num_philo)
	{
		pthread_create(&(checker->index[i].philo_thread), NULL, philo_routine, &(checker->index[i]));
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
		while (1)
			usleep(1000);
		return (NULL);
	}
	if ((ptr->philo_id) % 2 != 0)
		ft_sleep(ptr->info->time_to_eat / 2);
	while (1)
	{
		if (check_dead_flag(ptr) == 1)
			break ;
		philo_action(ptr);
	}
	pthread_exit(NULL);
}

void	philo_action(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "is eating");
	ft_sleep(philo->info->time_to_eat);
	pthread_mutex_lock(&(philo->meal_time));
	philo->last_meal_time = get_time();
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->meal_time));
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_status(philo, "is sleeping");
	ft_sleep(philo->info->time_to_sleep);
	print_status(philo, "is thinking");
}	
