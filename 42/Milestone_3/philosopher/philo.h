/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:32:06 by seungele          #+#    #+#             */
/*   Updated: 2026/06/27 19:34:31 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

typedef struct	s_philo {
	int				philo_id;
	long long		last_meal_time;
	pthread_t	philo_thread;
	pthread_mutex_t	meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	check_t		*info;
} philo_t;

typedef struct	s_check {
	int			is_dead;
	long long	num_philo;
	long long	time_to_eat;
	long long	time_to_die;
	long long	time_to_sleep;
	long long	now_time;
	long long	num_philo_eat;
	philo_t		*index;
	pthread_mutex_t	*forks;
} check_t;

long long	ft_atoi(char *c);
long long	check_overflow(long long a, int next, int sign);
void	check_num(char *c);

void	check_dead(check_t *checker);
long long	get_time(void);

void	free_all(check_t *checker);

void	make_philo(check_t *checker, int ac, char **av);
int	give_num(check_t *checker);
void	make_fork(check_t *checker);
void	make_routine(check_t *checker);
void	*philo_routine(void *arg);

#endif
