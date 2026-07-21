/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:35:23 by sangjpar          #+#    #+#             */
/*   Updated: 2026/03/04 13:38:04 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../ft_printf.h"
#include "../libft.h"

int	g_flag;

int	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
		return (1);
	else
		return (0);
}

void	ft_send(pid_t pid, char *input)
{
	int				i;
	int				size;
	unsigned char	a;

	i = 0;
	size = ft_strlen(input);
	while (i <= size)
	{
		a = 0b10000000;
		while (a >= 0b00000001)
		{
			if ((input[i] & a) == a)
				ft_kill(pid, SIGUSR1);
			else
				ft_kill(pid, SIGUSR2);
			a = a >> 1;
			while (g_flag == 0)
				usleep(50);
			g_flag = 0;
		}
		i++;
	}
}

void	check_ack(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		g_flag = 1;
}

void	init_sig(void)
{
	static struct sigaction	act;

	act.sa_handler = check_ack;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	return ;
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	g_flag = 0;
	init_sig();
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
		return (1);
	ft_send(pid, av[2]);
	return (0);
}
