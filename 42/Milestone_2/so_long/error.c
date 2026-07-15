/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:17:57 by seungele          #+#    #+#             */
/*   Updated: 2026/03/13 16:13:40 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_wall(t_map *game)
{
	int	i;

	i = 0;
	while (i < game->map_row)
	{
		if (game->map[0][i] != '1' || game->map[game->map_col - 1][i] != '1')
			error_exit("Invalid map shape\n", game);
		i++;
	}
	i = 0;
	while (i < game->map_col)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_row - 1] != '1')
			error_exit("Invalid map shape\n", game);
		i++;
	}
}

void	check_error(t_map *game)
{
	is_rectangle(game);
	is_wall(game);
	check_dest(game);
	copy_map(game);
	flood_fill(game, game->dest.x, game->dest.y);
	valid_map(game);
}

void	is_rectangle(t_map *game)
{
	int	size;
	int	i;

	if (!game->map || !game->map[0])
		error_exit("Empty map", game);
	size = get_len(game->map[0]);
	if (size < 3)
		error_exit("Map too narrow\n", game);
	game->map_row = size;
	i = 0;
	while (game->map[i] != NULL)
	{
		if (size != get_len(game->map[i]))
			error_exit("Invalid shape\n", game);
		i++;
	}
	if (i < 3)
		error_exit("Map too small\n", game);
	game->map_col = i;
}

int	get_len(char *c)
{
	int	len;

	len = ft_strlen(c);
	if (len > 0 && c[len - 1] == '\n')
		return (len - 1);
	return (len);
}
