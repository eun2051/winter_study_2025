#include "so_long.h"

void    flood_fill(t_map *game, int x, int y)
{
    if (x < 0 || x >= game->map_row || y < 0 || y >= game->map_col)
        return ;
    if (game->copy[y][x] == '1' || game->copy[y][x] == 'v')
        return ;
    game->copy[y][x] = 'v';
    flood_fill(game, x - 1, y);
    flood_fill(game, x, y - 1);
    flood_fill(game, x, y + 1);
    flood_fill(game, x + 1, y);
}

void    valid_map(t_map *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_col)
    {
        j = 0;
        while (j < game->map_row)
        {
            if (game->copy[i][j] == 'C' || game->copy[i][j] == 'E')
            {
                write(2, "Error\nInvalid map\n", 19);
                free_copy(game->copy);
                exit(1);
            }
            j++;
        }
        i++;
    }
    free_copy(game->copy);
}

void    free_copy(char **c)
{
    int i;

    i = 0;
    while (c[i] != NULL)
    {
        free(c[i]);
        i++;
    }
    free(c);
}

void    copy_map(t_map *game)
{
    int i;

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