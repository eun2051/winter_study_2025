/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:32:06 by seungele          #+#    #+#             */
/*   Updated: 2026/06/29 10:45:14 by seungele         ###   ########.fr       */
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

typedef struct s_check	t_check;

typedef struct s_philo {
	int				philo_id;
	int				thread_id;
	int				eat_cnt;
	long long		last_meal_time;
	pthread_t		philo_thread;
	pthread_mutex_t	meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_check			*info;
}	t_philo;

typedef struct s_check {
	int				is_dead;
	long long		num_philo;
	long long		time_to_eat;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		now_time;
	long long		num_philo_eat;
	t_philo			*index;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
}	t_check;

long long	ft_atoi(char *c);
long long	check_overflow(long long a, int next, int sign);
void		check_num(char *c);

void		check_dead(t_check *checker);
void		ft_sleep(long long wait_time);
long long	get_time(void);
int			check_dead_flag(t_philo *philo);

void		free_all(t_check *checker);

void		make_philo(t_check *checker, int ac, char **av);
int			give_num(t_check *checker);
void		make_fork(t_check *checker);
void		join_thread(t_check *checker);

void		make_routine(t_check *checker);
void		*philo_routine(void *arg);
void		philo_action(t_philo *philo);

void		print_status(t_philo *philo, char *status);

#endif
