/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:42:24 by seungele          #+#    #+#             */
/*   Updated: 2026/03/06 19:46:18 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_map *game)
{
	if (keycode == W)
		check_player(game, game->dest.x, game->dest.y - 1);
	else if (keycode == S)
		checK_player(game, game->dest.x, game->dest.y + 1);
	else if (keycode == A)
		check_player(game, game->dest.x - 1, game->dest.y);
	else if (keycode == D)
		check_player(game, game->dest.x + 1, game->dest.y);
	else if (keycode == ESC)
		exit(0);
	return (0);
}

void	check_player(t_map *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == 'C')
		game->c_cnt--;
	else if (game->map[y][x] == 'E')
	{
		if (game->c_cnt == 0)
			exit(0);
		return ;
	}
	game->map[game->dest.y][game->dest.x] = '0';
	game->dest.x = x;
	game->dest.y = y;
	game->map[y][x] = 'P';
	game->move_cnt++;
	ft_printf("Move count: %d\n", game->move_cnt);
	img_map(game);
}

int	close_map(void)
{
	exit(0);
	return (0);
}
