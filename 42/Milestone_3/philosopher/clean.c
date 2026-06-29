/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:22:01 by seungele          #+#    #+#             */
/*   Updated: 2026/06/27 19:27:20 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(check_t *checker)
{
	int	i;

	i = 0;
	while (i < checker->num_philo)
	{
		pthread_mutex_destroy(&(checker->forks[i]));
		pthread_mutex_destroy(&(checker->index[i].meal_time));
		i++;
	}
	free(checker->forks);
	free(checker->index);
}
