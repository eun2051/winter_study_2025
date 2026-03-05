#include "so_long.h"

void    img_map(t_map *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_col)
    {
        j = 0;
        while (j < game->map_row)
        {
            mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.floor, j * 64, i * 64);
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.wall, j * 64, i * 64);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.player, j * 64, i * 64);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.collect, j * 64, i * 64);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void    put_img(t_map *game)
{
    int w;
    int h;

    game->mlx.img.player = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./textures/player.xpm", &w, &h);
    game->mlx.img.floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./textures/floor.xpm", &w, &h);
    game->mlx.img.wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./textures/wall.xpm", &w, &h);
    game->mlx.img.collect = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./textures/collectives.xpm", &w, &h);
    game->mlx.img.exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "./textures/exit.xpm", &w, &h);

    if (!game->mlx.img.player || !game->mlx.img.floor || !game->mlx.img.wall || !game->mlx.img.collect || !game->mlx.img.exit)
    {
        write(2, "Error\nFailed to load images\n", 28);
        exit(1);
    }
}