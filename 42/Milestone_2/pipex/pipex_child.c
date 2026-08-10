/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:14 by seungele          #+#    #+#             */
/*   Updated: 2026/02/11 12:22:16 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	error_exit(char *msg, int code, char **arr)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (arr)
		free_arr(arr);
	exit(code);
}

void	execute_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = get_cmd(av);
	if (!cmd || !cmd[0])
	{
		error_exit("command not found", 127, cmd);
		exit(127);
	}
	path = get_final_path(cmd[0], envp);
	if (!path)
	{
		if (ft_strchr(cmd[0], '/'))
			error_exit("No such file or directory", 127, cmd);
		else
			error_exit("command not found", 127, cmd);
	}
	execve(path, cmd, envp);
	perror(cmd[0]);
	free(path);
	free_arr(cmd);
	exit(126);
}

int	make_child(char *cmd, int prev_fd, char **envp)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (prev_fd < 0)
			exit(1);
		dup2(prev_fd, 0);
		close(prev_fd);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execute_cmd(cmd, envp);
	}
	else
	{
		close(prev_fd);
		close(fd[1]);
		return (fd[0]);
	}
	return (-1);
}

pid_t	last_child(char *cmd, int prev_fd, char *outfile, char **envp)
{
	int	pid;
	int	out_fd;

	pid = fork();
	if (pid == 0)
	{
		out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd < 0)
		{
			perror(outfile);
			exit(1);
		}
		dup2(prev_fd, 0);
		close(prev_fd);
		dup2(out_fd, 1);
		close(out_fd);
		execute_cmd(cmd, envp);
	}
	close(prev_fd);
	return (pid);
}
