/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:27:26 by seungele          #+#    #+#             */
/*   Updated: 2026/04/03 18:27:28 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clear_all(t_map *game)
{
	if (game->map)
		free_map(game->map);
	if (game->copy)
		free_map(game->copy);
	if (game->mlx.mlx_ptr)
	{
		if (game->mlx.img.player)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.player);
		if (game->mlx.img.wall)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.wall);
		if (game->mlx.img.floor)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.floor);
		if (game->mlx.img.collect)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.collect);
		if (game->mlx.img.exit)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.exit);
		if (game->mlx.win_ptr)
		{
			mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
			free(game->mlx.mlx_ptr);
		}
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}

void	error_exit(char *msg, t_map *game)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	clear_all(game);
	exit(1);
}
