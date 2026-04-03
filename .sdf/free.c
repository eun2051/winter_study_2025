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

void	clear_all(t_map *game)
{
	if (game->map)
		free_copy(game->map);
	if (game->copy)
		free_copy(game->copy);
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
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}
