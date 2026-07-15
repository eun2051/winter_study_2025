/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:26:06 by seungele          #+#    #+#             */
/*   Updated: 2026/06/29 10:06:37 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&(philo->info->print_lock));
	if (philo->info->is_dead == 1)
		return ;
	printf("%lld %d %s\n", get_time() - philo->info->now_time, philo->philo_id, status);
	pthread_mutex_unlock(&(philo->info->print_lock));
}
