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

void	read_map(int fd, t_map *game)
{
	int		cnt;
	char	*line;

	cnt = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		cnt++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map_col = cnt;
}

void	make_map(char *c, t_map *game)
{
	int		fd;
	int		i;
	int		size;
	char	*line;

	if (check_ber(c) == 1)
		exit(1);
	fd = open(c, O_RDONLY);
	read_map(fd, game);
	size = game->map_col;
	fd = open(c, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[size] = NULL;
	close(fd);
	return ;
}

int	check_ber(char *c)
{
	int	size;

	size = ft_strlen(c);
	if (size > 4)
	{
		if (ft_strncmp(c + size - 4, ".ber", 4) != 0)
		{
			write(2, "Error\nInvalid extension\n", 24);
			return (1);
		}
		return (0);
	}
	return (1);
}
