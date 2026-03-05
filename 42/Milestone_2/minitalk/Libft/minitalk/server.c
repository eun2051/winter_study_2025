/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:54:34 by sangjpar          #+#    #+#             */
/*   Updated: 2026/03/04 13:38:17 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../libft.h"
#include "../ft_printf.h"

typedef struct s_signal
{
	int		flag;
	int		signum;
	pid_t	pid;
}	t_signal;

t_signal	g_var;

void	takemsg_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		g_var.signum = signum;
		g_var.flag = 1;
	}
	g_var.pid = info -> si_pid;
}

void	init_sig(void)
{
	static struct sigaction	act;

	act.sa_sigaction = takemsg_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	return ;
}

void	print_char(int *num, char *res)
{
	while (g_var.flag == 0)
		usleep(50);
	if (g_var.flag == 1)
	{
		(*res) <<= 1;
		if (g_var.signum == SIGUSR1)
			*res += 0B00000001;
		g_var.flag = 0;
		if (*num < 7)
			kill(g_var.pid, g_var.signum);
	}
}

int	main(void)
{
	pid_t		pid;
	static char	res;
	static int	num;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	init_sig();
	while (1)
	{
		res = 0B00000000;
		while (num < 8)
		{
			print_char(&num, &res);
			num++;
		}
		num = 0;
		if (res == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", res);
		kill(g_var.pid, g_var.signum);
	}
	return (0);
}
