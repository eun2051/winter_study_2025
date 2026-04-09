/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:46:34 by seungele          #+#    #+#             */
/*   Updated: 2026/03/13 16:17:51 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_lines(int fd)
{
	char	*line;
	char	*all;
	char	*temp;

	all = ft_strdup("");
	if (!all)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = all;
		all = ft_strjoin(all, line);
		free(temp);
		free(line);
		if (!all)
			return (NULL);
	}
	return (all);
}

void	check_lines(char *all, t_map *game)
{
	if (!all || all[0] == '\0')
	{
		free(all);
		error_exit("Empty map file", game);
	}
	if (all[0] == '\n' || ft_strnstr(all, "\n\n", ft_strlen(all)))
	{
		free(all);
		error_exit("Invalid map: empty line detected", game);
	}
}

void	make_map(char *c, t_map *game)
{
	int		fd;
	char	*all;

	if (check_ber(c) == 1)
		error_exit("Invalid extenstion\n", game);
	fd = open(c, O_RDONLY);
	if (fd < 0)
		error_exit("File open failed\n", game);
	all = read_lines(fd);
	close(fd);
	check_lines(all, game);
	game->map = ft_split(all, '\n');
	free(all);
	if (!game->map)
		error_exit("Map fail\n", game);
}

int	check_ber(char *c)
{
	int	size;

	size = ft_strlen(c);
	if (size > 4)
	{
		if (ft_strncmp(c + size - 4, ".ber", 4) != 0)
			return (1);
		return (0);
	}
	return (1);
}
