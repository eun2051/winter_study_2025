/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 08:32:40 by seungele          #+#    #+#             */
/*   Updated: 2026/07/24 16:39:16 by seungele         ###   ########.fr       */
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

typedef struct s_check {
	int		is_dead;
	long long	num_philo;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	now_time;
	long long	num_philo_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
}	t_check;

typedef struct s_philo {
	int		philo_id;
	int		eat_cnt;
	long long	last_meal_time;
	pthread_t	philo_thread;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	t_check	*info;
}	t_philo;

long long	ft_atoi(char *c);
long long	check_overflow(long long a, int next, int sign);
void		check_num(char *c);
void		init_check(t_check *checker, int ac, char **av);
t_philo		*init_philo(t_check *checker);
void		init_fork(t_check *checker):

#endif
