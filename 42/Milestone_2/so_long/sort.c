/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:51:35 by seungele          #+#    #+#             */
/*   Updated: 2026/03/13 16:04:07 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *game, int x, int y)
{
	if (x < 0 || x >= game->map_row || y < 0 || y >= game->map_col)
		return ;
	if (game->copy[y][x] == '1' || game->copy[y][x] == 'v')
		return ;
	if (game->copy[y][x] == 'E')
	{
		game->copy[y][x] = 'v';
		return ;
	}
	game->copy[y][x] = 'v';
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
	flood_fill(game, x + 1, y);
}

void	valid_map(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_col)
	{
		j = 0;
		while (j < game->map_row)
		{
			if (valid_element(game->copy[i][j]))
				error_exit("Invalid path\n", game);
			j++;
		}
		i++;
	}
	free_map(game->copy);
	game->copy = NULL;
}

int	valid_element(char c)
{
	if (c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

void	copy_map(t_map *game)
{
	int	i;

	game->copy = (char **)malloc(sizeof(char *) * (game->map_col + 1));
	if (!game->copy)
		return ;
	i = 0;
	while (i < game->map_col)
	{
		game->copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->copy[i] = NULL;
}
