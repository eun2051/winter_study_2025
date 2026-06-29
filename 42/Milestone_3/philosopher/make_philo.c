/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:45:52 by seungele          #+#    #+#             */
/*   Updated: 2026/06/27 19:34:52 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_philo(check_t *checker, int ac, char **av)
{
	checker->num_philo = ft_atoi(av[1]);
	checker->time_to_die = ft_atoi(av[2]);
	checker->time_to_eat = ft_atoi(av[3]);
	checker->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		checker->num_philo_eat = ft_atoi(av[5]);
}

int	give_num(philo_t *philo, check_t *checker)
{
	int	i;

	i = 0;
	checker->index = malloc(sizeof(philo_t) * checker->num_philo);
	if (checker->index == NULL)
		return (1);
	while (i < checker->num_philo)
	{
		checker->index[i].philo_id = i + 1;
		printf("1");
		i++;
	}
	return (0);
}

void	make_fork(check_t *checker)
{
	int	i;

	i = 0;
	checker->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *) * (checker->num_philo));
	while (i < checker->num_philo)
	{
		pthread_mutex_init(&(checker->forks[i]), NULL);
		i++;
	}
	i = 0;
	while (i < checker->num_philo)
	{
		checker->index[i].left_fork = &(checker->forks[i]);
		checker->index[i].right_fork = &(checker->forks[(i + 1) % (checker->num_philo)]);
		i++;
	}
}
