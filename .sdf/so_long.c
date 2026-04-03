/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:20:44 by seungele          #+#    #+#             */
/*   Updated: 2026/03/13 16:03:42 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	game;

	if (ac != 2)
	{
		write(2, "Error\nInvalid argument\n", 23);
		exit(1);
	}
	make_map(av[1], &game);
	param_init(&game);
	check_error(&game);
	game.mlx.mlx_ptr = mlx_init();
	game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, game.map_row * 64,
			game.map_col * 64, "so_long");
	put_img(&game);
	img_map(&game);
	game.move_cnt = 0;
	mlx_hook(game.mlx.win_ptr, 17, 0, close_map, &game);
	mlx_key_hook(game.mlx.win_ptr, key_press, &game);
	mlx_loop(game.mlx.mlx_ptr);
}
