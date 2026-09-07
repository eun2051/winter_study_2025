/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:38:41 by seungele          #+#    #+#             */
/*   Updated: 2026/02/11 19:43:43 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	last_pid;
	int	i;
	int	prev_fd;

	if (ac != 5)
	{
		ft_putstr_fd("Invalid Arguments\n", 2);
		return (1);
	}
	prev_fd = open(av[1], O_RDONLY);
	if (prev_fd < 0)
		perror(av[1]);
	i = 0;
	while (i < ac - 4)
		prev_fd = make_child(av[2 + i++], prev_fd, envp);
	last_pid = last_child(av[2 + i], prev_fd, av[ac - 1], envp);
	return (get_status(last_pid));
}

int	get_status(int last_pid)
{
	int	status;
	int	wait_pid;
	int	last_status;

	last_status = 0;
	while (1)
	{
		wait_pid = wait(&status);
		if (wait_pid == -1)
			break ;
		if (wait_pid == last_pid)
			last_status = status;
	}
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(last_status));
	return (0);
}
