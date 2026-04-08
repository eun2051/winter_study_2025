/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:21:01 by seungele          #+#    #+#             */
/*   Updated: 2026/03/14 15:48:34 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_map(t_map *game)
{
	int		i;
	int		j;
	t_img	*img;
	t_win	*cur;
	int		(*f)(void *, void *, void *, int, int);

	f = mlx_put_image_to_window;
	i = 0;
	cur = &game->mlx;
	img = &cur->img;
	while (i < game->map_col)
	{
		j = 0;
		while (j < game->map_row)
		{
			f(cur->mlx_ptr, cur->win_ptr, img->floor, j * 64, i * 64);
			draw_element(game, i, j);
			j++;
		}
		i++;
	}
}

void	draw_element(t_map *game, int i, int j)
{
	t_img	*img;
	t_win	*cur;
	int		(*f)(void *, void *, void *, int, int);

	f = mlx_put_image_to_window;
	cur = &game->mlx;
	img = &cur->img;
	if (game->map[i][j] == '1')
		f(cur->mlx_ptr, cur->win_ptr, img->wall, j * 64, i * 64);
	else if (game->map[i][j] == 'P')
		f(cur->mlx_ptr, cur->win_ptr, img->player, j * 64, i * 64);
	else if (game->map[i][j] == 'C')
		f(cur->mlx_ptr, cur->win_ptr, img->collect, j * 64, i * 64);
	else if (game->map[i][j] == 'E')
		f(cur->mlx_ptr, cur->win_ptr, img->exit, j * 64, i * 64);
}

void	put_img(t_map *game)
{
	int		w;
	int		h;
	t_img	img;
	t_win	*cur;
	void	*(*f)(void *, char *, int *, int *);

	cur = &game->mlx;
	img = cur->img;
	f = mlx_xpm_file_to_image;
	img.player = f(cur->mlx_ptr, "./textures/player.xpm", &w, &h);
	img.floor = f(cur->mlx_ptr, "./textures/floor.xpm", &w, &h);
	img.wall = f(cur->mlx_ptr, "./textures/wall.xpm", &w, &h);
	img.collect = f(cur->mlx_ptr, "./textures/collectives.xpm", &w, &h);
	img.exit = f(cur->mlx_ptr, "./textures/exit.xpm", &w, &h);
	cur->img = img;
	if (!img.player || !img.floor || !img.wall || !img.collect || !img.exit)
		error_exit("Image load failed\n", game);
}
