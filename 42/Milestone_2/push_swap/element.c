/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:22:48 by seungele          #+#    #+#             */
/*   Updated: 2026/03/14 15:46:37 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element(char c, t_map *game)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		error_exit("Invalid element\n", game);
}

void	check_dest(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			check_element(game->map[i][j], game);
			if (game->map[i][j] == 'P')
			{
				game->dest.x = j;
				game->dest.y = i;
				game->p_cnt++;
			}
			else if (game->map[i][j] == 'E')
				game->e_cnt++;
			else if (game->map[i][j] == 'C')
				game->c_cnt++;
		}
	}
	if (check_cnt(game) == 1)
		error_exit("Invalid character\n", game);
}

void	param_init(t_map *game)
{
	game->p_cnt = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->move_cnt = 0;
	game->map = NULL;
	game->copy = NULL;
	game->mlx.mlx_ptr = NULL;
	game->mlx.win_ptr = NULL;
	game->mlx.img.player = NULL;
	game->mlx.img.wall = NULL;
	game->mlx.img.floor = NULL;
	game->mlx.img.collect = NULL;
	game->mlx.img.exit = NULL;
}

int	check_cnt(t_map *game)
{
	if (game->p_cnt == 1 && game->e_cnt == 1 && game->c_cnt >= 1)
		return (0);
	return (1);
}
