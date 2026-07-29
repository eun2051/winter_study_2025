/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:58:54 by seungele          #+#    #+#             */
/*   Updated: 2026/07/27 21:52:02 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_philo *p, t_check *checker)
{
	int	i;

	i = 0;
	while (i < checker->num_philo)
	{
		pthread_join(p[i].philo_thread, NULL);
		pthread_mutex_destroy(&(checker->forks[i]));
		pthread_mutex_destroy(&(p[i].meal_lock));
		i++;
	}
	pthread_mutex_destroy(&(checker->print_lock));
	pthread_mutex_destroy(&(checker->dead_lock));
	free(checker->forks);
	free(p);
}
