/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:30:21 by seungele          #+#    #+#             */
/*   Updated: 2026/06/27 19:17:27 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_routine(check_t *checker)
{
	int			i;

	i = 0;
	while (i < checker->num_philo)
	{
		pthread_create(&(checker->index[i].philo_thread), NULL, philo_routine, &(checker->index[i]));
		i++;
	}
	i = 0;
	while (i < checker->num_philo)
	{
		pthread_join(checker->index[i].philo_thread, NULL);
		i++;
	}
}

void	*philo_routine(void *arg)
{
	 philo_t	*ptr;

	 ptr = (philo_t *)arg;
	 if ((ptr->philo_id) % 2 != 0)
		 usleep(((ptr->info->time_to_eat) / 2) * 1000);
	 while (1)
	 {
		 if (ptr->info->is_dead == 1)
			 break;
		 pthread_mutex_lock(ptr->left_fork);
		 pthread_mutex_lock(ptr->right_fork);
		 printf("%d is eating\n", ptr->philo_id);
		 usleep((ptr->info->time_to_eat) * 1000);
		 ptr->last_meal_time = get_time();
		 pthread_mutex_unlock(ptr->left_fork);
		 pthread_mutex_unlock(ptr->right_fork);
		 printf("%d is sleeping\n", ptr->philo_id);
		 usleep((ptr->info->time_to_sleep) * 1000);
		 printf("%d is thinking\n", ptr->philo_id);
	 }
	 pthread_exit(NULL);
}
