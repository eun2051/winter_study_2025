/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:36:28 by seungele          #+#    #+#             */
/*   Updated: 2026/06/28 08:58:23 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(check_t *checker)
{
	int			i;
	long long	time;

	i = 0;
	checker->is_dead = 0;
	while (1)
	{
		while (i < checker->num_philo)
		{
			pthread_mutex_lock(&(checker->index[i].meal_time));
			time = (get_time()) - (checker->index[i].last_meal_time);
			pthread_mutex_unlock(&(checker->index[i].meal_time));
			if (time > checker->time_to_die)
			{
				printf("%d is dead\n", checker->index[i].philo_id);
				checker->is_dead = 1;
				return ;
			}
			i++;
		}
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
