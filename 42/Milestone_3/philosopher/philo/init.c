/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:47:53 by seungele          #+#    #+#             */
/*   Updated: 2026/07/30 18:38:00 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_check(t_check *checker, int ac, char **av)
{
	checker->num_philo = ft_atoi(av[1]);
	checker->time_to_die = ft_atoi(av[2]);
	checker->time_to_eat = ft_atoi(av[3]);
	checker->time_to_sleep = ft_atoi(av[4]);
	checker->num_philo_eat = 0;
	if (ac == 6)
		checker->num_philo_eat = ft_atoi(av[5]);
	if (checker->num_philo <= 0 || checker->time_to_die <= 0 ||
		       	checker->time_to_eat <= 0 || checker->time_to_sleep <= 0)
		return (1);
	if (ac == 6 && checker->num_philo_eat <= 0)
		return (1);
	checker->is_dead = 0;
	pthread_mutex_init(&(checker->print_lock), NULL);
	pthread_mutex_init(&(checker->dead_lock), NULL);
	return (0);
}

t_philo	*init_philo(t_check *checker)
{
	int		i;
	t_philo	*philo;

	i = 0;
	if (init_fork(checker) == 1)
		return (NULL);
	philo = malloc(sizeof(t_philo) * checker->num_philo);
	if (!philo)
		return (NULL);
	while (i < checker->num_philo)
	{
		philo[i].last_meal_time = get_time();
		philo[i].philo_id = i + 1;
		philo[i].info = checker;
		philo[i].eat_cnt = 0;
		pthread_mutex_init(&(philo[i].meal_lock), NULL);
		philo[i].left_fork = &(checker->forks[i]);
		philo[i].right_fork = &(checker->forks[(i + 1) % checker->num_philo]);
		i++;
	}
	return (philo);
}

int	init_fork(t_check *checker)
{
	int	i;

	i = 0;
	checker->forks = malloc(sizeof(t_fork) * (checker->num_philo));
	if (!checker->forks)
		return (1);
	while (i < checker->num_philo)
	{
		pthread_mutex_init(&(checker->forks[i].fork_mutex), NULL);
		checker->forks[i].is_taken = 0;
		i++;
	}
	return (0);
}
