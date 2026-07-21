/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:45:52 by seungele          #+#    #+#             */
/*   Updated: 2026/06/28 19:25:07 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_philo(t_check *checker, int ac, char **av)
{
	checker->num_philo = ft_atoi(av[1]);
	checker->time_to_die = ft_atoi(av[2]);
	checker->time_to_eat = ft_atoi(av[3]);
	checker->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		checker->num_philo_eat = ft_atoi(av[5]);
}

int	give_num(t_check *checker)
{
	int	i;

	i = 0;
	checker->index = malloc(sizeof(t_philo) * checker->num_philo);
	if (checker->index == NULL)
		return (1);
	while (i < checker->num_philo)
	{
		checker->index[i].last_meal_time = get_time();
		checker->index[i].philo_id = i + 1;
		checker->index[i].info = checker;
		checker->index[i].eat_cnt = 0;
		pthread_mutex_init(&(checker->index[i].meal_time), NULL);
		i++;
	}
	return (0);
}

void	make_fork(t_check *checker)
{
	int		i;
	int		num;

	i = 0;
	num = checker->num_philo;
	pthread_mutex_init(&(checker->print_lock), NULL);
	pthread_mutex_init(&(checker->dead_lock), NULL);
	checker->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	while (i < checker->num_philo)
	{
		pthread_mutex_init(&(checker->forks[i]), NULL);
		i++;
	}
	i = 0;
	while (i < checker->num_philo)
	{
		checker->index[i].left_fork = &(checker->forks[i]);
		checker->index[i].right_fork = &(checker->forks[(i + 1) % num]);
		i++;
	}
}

void	join_thread(t_check *checker)
{
	int	i;

	i = 0;
	while (i < checker->num_philo)
	{
		pthread_join(checker->index[i].philo_thread, NULL);
		i++;
	}
}
