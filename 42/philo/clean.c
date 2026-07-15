/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:22:01 by seungele          #+#    #+#             */
/*   Updated: 2026/06/28 09:59:40 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_check *checker)
{
	int	i;

	i = 0;
	while (i < checker->num_philo)
	{
		pthread_mutex_destroy(&(checker->forks[i]));
		pthread_mutex_destroy(&(checker->index[i].meal_time));
		i++;
	}
	pthread_mutex_destroy(&(checker->print_lock));
	free(checker->forks);
	free(checker->index);
}
