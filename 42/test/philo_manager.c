/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:40:39 by seungele          #+#    #+#             */
/*   Updated: 2026/07/27 23:42:25 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_philo *philo, t_check *checker)
{
	int	i;

	i = 0;
	checker->now_time = get_time();
	while (i < checker->num_philo)
	{
		pthread_mutex_lock(&(philo[i].meal_lock));
		philo[i].last_meal_time = checker->now_time;
		pthread_mutex_unlock(&(philo[i].meal_lock));
		pthread_create(&(philo[i].philo_thread), NULL, philo_routine, &(philo[i]));
		i++;
	}
}

void	*philo_routine(void *arg)
{
	int		flag;
	t_philo	*ptr;

	ptr = (t_philo *)arg;
	flag = 0;
	if (ptr->info->num_philo == 1)
	{
		pthread_mutex_lock(ptr->left_fork);
		print_status(ptr, "has taken a fork");
		while (check_dead_flag(ptr) == 0)
			usleep(200);
		pthread_mutex_unlock(ptr->left_fork);
		return (NULL);
	}
	if ((ptr->philo_id) % 2 != 0)
		ft_sleep(ptr->info->time_to_eat / 2);
	while (1)
	{
		flag = check_dead_flag(ptr);
		if (flag == 1)
			break;
		philo_action(ptr);
	}
	pthread_exit(NULL);
}

void	philo_action(t_philo *philo)
{
	long long	think_time;
	if (check_dead_flag(philo))
		return ;
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&(philo->meal_lock));
	philo->last_meal_time = get_time();
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->meal_lock));
	ft_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (check_dead_flag(philo))
		return ;
	print_status(philo, "is sleeping");
	ft_sleep(philo->info->time_to_sleep);
	print_status(philo, "is thinking");
	if (philo->info->num_philo % 2 != 0)
	{
		think_time = (philo->info->time_to_die - (philo->info->time_to_eat + philo->info->time_to_sleep)) / 2;
		if (think_time > 0)
			ft_sleep(think_time);
	}
}

void	check_dead(t_philo *philo, t_check *checker)
{
	int	i;
	int	full_cnt;
	long long	time;

	while (1)
	{
		i = 0;
		full_cnt = 0;
		while (i < checker->num_philo)
		{
			pthread_mutex_lock(&(philo[i].meal_lock));
			time = get_time() - philo[i].last_meal_time;
			if (time >= checker->time_to_die)
			{
				pthread_mutex_lock(&(checker->dead_lock));
				checker->is_dead = 1;
				pthread_mutex_unlock(&(checker->dead_lock));
				pthread_mutex_lock(&(checker->print_lock));
				printf("%lld %d died\n", get_time() - checker->now_time, philo[i].philo_id);
				pthread_mutex_unlock(&(checker->print_lock));
				pthread_mutex_unlock(&(philo[i].meal_lock));
				return ;
			}
			if (checker->num_philo_eat > 0 && philo[i].eat_cnt >= checker->num_philo_eat)
				full_cnt++;
			pthread_mutex_unlock(&(philo[i].meal_lock));
			i++;
		}
		if (checker->num_philo_eat > 0 && full_cnt == checker->num_philo)
		{
			pthread_mutex_lock(&(checker->dead_lock));
			checker->is_dead = 1;
			pthread_mutex_unlock(&(checker->dead_lock));
			return ;
		}
		usleep(200);
	}
}
