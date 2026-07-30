/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 08:32:40 by seungele          #+#    #+#             */
/*   Updated: 2026/07/30 18:50:49 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_fork {
	pthread_mutex_t	fork_mutex;
	int				is_taken;
}	t_fork;

typedef struct s_check {
	int				is_dead;
	long long		num_philo;
	long long		time_to_eat;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		now_time;
	long long		num_philo_eat;
	t_fork			*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
}	t_check;

typedef struct s_philo {
	int				philo_id;
	int				eat_cnt;
	long long		last_meal_time;
	pthread_t		philo_thread;
	pthread_mutex_t	meal_lock;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_check			*info;
}	t_philo;

long long		ft_atoi(char *c);
long long		check_overflow(long long a, int next, int sign);
void			check_num(char *c);
void			ft_putnbr_fd(long long n, int fd);
size_t			ft_strlen(const char *s);

int				init_check(t_check *checker, int ac, char **av);
t_philo			*init_philo(t_check *checker);
int				init_fork(t_check *checker);

void			start_threads(t_philo *philo, t_check *checker);
void			*philo_routine(void *arg);
void			philo_action(t_philo *philo);
void			check_dead(t_philo *philo, t_check *checker);

long long		get_time(void);
void			print_status(t_philo *philo, char *status);
void			print_util(long long time, int philo_id, char *status);
void			ft_sleep(long long wait_time);
int				check_dead_flag(t_philo *philo);

void			cleanup(t_philo *p, t_check *checker);

int				take_one_fork(t_philo *philo, t_fork *fork);
int				taking_fork(t_philo *philo);
void			unlock_fork(t_philo *philo);
void			thinking_time(t_philo *philo);

int				count_check(int full_cnt, t_check *checker);
int				time_dead(int i, t_philo *philo, t_check *checker);

#endif
