/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:37:30 by seungele          #+#    #+#             */
/*   Updated: 2026/06/29 10:58:26 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_routine(t_check *checker)
{
	t_philo	*ptr;
	int	i;

	i = 0;
	checker->now_time = get_time();
	while (i < checker->num_philo)
	{
		checker->thread_id = i;
		pthread_create(&(checker->index[i].philo_thread), NULL, philo_routine, &(checker));
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo *ptr;
	t_check	*checker;

	ptr = (t_philo *)arg;
	if (checker->num_philo == 1)
	{
		pthread_mutex_lock(ptr->left_fork);
		print_status(ptr, "has taken a fork");
		while (1)
			usleep(1000);
		return (NULL);
	}
	if (ptr->philo_id) % 2 != 0)
		ft_sleep(checker->time_to_eat / 2);
	while (1)
	{
		if (check_dead_flag(ptr) == 1)
			break;
		philo_action(ptr);
	}
	pthread_exit(NULL);
}

void	philo_action(t_check *checker)
{

}
