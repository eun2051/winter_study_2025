/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:33:36 by seungele          #+#    #+#             */
/*   Updated: 2026/02/11 13:33:38 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *av)
{
	return (ft_split_pipex(av, ' '));
}

char	**get_path(char **envp)
{
	int		i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **all_path)
{
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	while (all_path[i])
	{
		tmp = ft_strjoin(all_path[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_final_path(char *av, char **envp)
{
	char	**path_list;
	char	*all_path;

	if (!av)
		return (NULL);
	if (ft_strchr(av, '/'))
	{
		if (access(av, F_OK) == 0)
			return (ft_strdup(av));
		return (NULL);
	}
	path_list = get_path(envp);
	if (!path_list)
		return (NULL);
	all_path = find_path(av, path_list);
	free_arr(path_list);
	return (all_path);
}
