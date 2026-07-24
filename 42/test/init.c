/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:47:53 by seungele          #+#    #+#             */
/*   Updated: 2026/07/24 16:59:52 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_check(t_check *checker, int ac, char **av)
{
	checker->num_philo = ft_atoi(av[1]);
	checker->time_to_die = ft_atoi(av[2]);
	checker->time_to_eat = ft_atoi(av[3]);
	checker->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		checker->num_philo_eat = ft_atoi(av[5]);
	checker->is_dead = 0;
	pthread_mutex_init((&(checker->print_lock), NULL);
	pthread_mutex_init((), NULL);
	checker->print_lock = ;
	checker->dead_lock;
}

t_philo	*init_philo(t_check *checker)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * checker->num_philo);
	if (!philo)
		return (NULL);
	init_fork(checker);
	while (i < checker->num_philo)
	{
		philo[i].last_meal_time = get_time();
		philo[i].philo_id = i + 1;
		philo[i].info = checker;
		philo[i].eat_cnt = 0;
		pthread_mutex_init(&(philo[i].meal_time), NULL);
		philo[i].left_fork = &(checker->forks[i]);
		philo[i].right_fork = &(checker->forks[(i + 1) % checker->num_philo]);
		i++;
	}
	return (philo);
}

void	init_fork(t_check *checker)
{
	int	i;

	i = 0;
	checker->forks = malloc(sizeof(pthread_mutex_t) * (checker->num_philo));
	while (i < checker->num_philo)
	{
		pthread_mutex_init(&(checker->forks[i]), NULL);
		i++;
	}
}
