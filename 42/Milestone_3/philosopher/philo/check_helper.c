/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:31:16 by seungele          #+#    #+#             */
/*   Updated: 2026/07/30 18:53:44 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	count_check(int full_cnt, t_check *checker)
{
	if (checker->num_philo_eat > 0 && full_cnt == checker->num_philo)
	{
		pthread_mutex_lock(&(checker->dead_lock));
		checker->is_dead = 1;
		pthread_mutex_unlock(&(checker->dead_lock));
		return (1);
	}
	return (0);
}

int	time_dead(int i, t_philo *philo, t_check *checker)
{
	long long	time;
	long long	cur_time;

	pthread_mutex_lock(&(philo[i].meal_lock));
	time = get_time() - philo[i].last_meal_time;
	if (time >= checker->time_to_die)
	{
		pthread_mutex_lock(&(checker->dead_lock));
		checker->is_dead = 1;
		pthread_mutex_unlock(&(checker->dead_lock));
		pthread_mutex_lock(&(checker->print_lock));
		cur_time = get_time() - checker->now_time;
		print_util(cur_time, philo[i].philo_id, "died");
		pthread_mutex_unlock(&(checker->print_lock));
		pthread_mutex_unlock(&(philo[i].meal_lock));
		return (1);
	}
	pthread_mutex_unlock(&(philo[i].meal_lock));
	return (0);
}
