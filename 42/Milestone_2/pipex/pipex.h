/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:38 by seungele          #+#    #+#             */
/*   Updated: 2026/02/11 12:27:21 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "Libft/libft.h"

int		make_child(char *cmd, int prev_fd, char **envp);
int		make_str_pipex(char **result, const char *s, char c);
int		get_status(int last_pid);
pid_t	last_child(char *cmd, int prev_fd, char *outfile, char **envp);
size_t	word_cnt_pipex(char const *s, char c);
size_t	get_word_len(const char *s, char c);
void	free_arr(char **av);
void	execute_cmd(char *av, char **envp);
void	error_exit(char *msg, int code, char **arr);
char	*find_path(char *cmd, char **all_path);
char	*ft_strndup_pipex(char const *s, size_t len);
char	*get_final_path(char *av, char **envp);
char	**get_cmd(char *av);
char	**ft_split_pipex(char const *s, char c);

#endif
