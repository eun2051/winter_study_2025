/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:36:28 by seungele          #+#    #+#             */
/*   Updated: 2026/06/29 10:09:30 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_check *checker)
{
	int			i;
	int			full_cnt;
	long long	time;

	i = 0;
	checker->is_dead = 0;
	while (1)
	{
		i = 0;
		full_cnt = 0;
		while (i < checker->num_philo)
		{
			pthread_mutex_lock(&(checker->index[i].meal_time));
			time = (get_time() - (checker->index[i].last_meal_time));
			if (checker->num_philo_eat != 0 && checker->index[i].eat_cnt >= checker->num_philo_eat)
				full_cnt++;
			pthread_mutex_unlock(&(checker->index[i].meal_time));
			if (time >= checker->time_to_die)
			{
				pthread_mutex_lock(&(checker->dead_lock));
				checker->is_dead = 1;
				pthread_mutex_unlock(&(checker->dead_lock));
				pthread_mutex_lock(&(checker->print_lock));
				printf("%lld %d died\n", get_time() - checker->now_time, checker->index[i].philo_id);
				pthread_mutex_unlock(&(checker->print_lock));
				free_all(checker);
				exit(0);
			}
			i++;
		}
		if (checker->num_philo_eat != 0 && full_cnt == checker->num_philo)
		{
			pthread_mutex_lock(&(checker->dead_lock));
			checker->is_dead = 1;
			printf("%lld %d died\n", get_time() - checker->now_time, checker->index[i].philo_id);
			pthread_mutex_unlock(&(checker->dead_lock));
			return ;
		}
	}
}

void	ft_sleep(long long wait_time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < wait_time)
	{
		usleep(500);
	}
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = ((long long)tv.tv_sec * 1000) + ((long long)tv.tv_usec / 1000);
	return (time);
}

int	check_dead_flag(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&(philo->info->dead_lock));
	flag = philo->info->is_dead;
	pthread_mutex_unlock(&(philo->info->dead_lock));
	return (flag);
}
