#include "so_long.h"

void    is_wall(t_map *game)
{
    int i;

    i = 0;
    while (i < game->map_row)
    {
        if (game->map[0][i] != '1' || game->map[game->map_col - 1][i] != '1')
        {
            write(2, "Error\nInvalid map shape\n", 24);
            exit(1);
        }
        i++;
    }
    i = 0;
    while (i < game->map_col)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_row - 1] != '1')
        {
            write(2, "Error\nInvalid map shape\n", 24);
            exit(1);
        }
        i++;
    }
}

void    check_error(t_map *game)
{
    is_rectangle(game);
    is_wall(game);
    check_dest(game);
    copy_map(game);
    flood_fill(game, game->dest.x, game->dest.y);
    valid_map(game);
}

void    is_rectangle(t_map *game)
{
    int size;
    int i;

    size = get_len(game->map[0]);
    game->map_row = size;
    i = 0;
    while (game->map[i] != NULL)
    {
        if (size != get_len(game->map[i]))
        {
            write(2, "Error\nInvalid map shape\n", 24);
            exit(1);
        }
        i++;
    }
}

int get_len(char *c)
{
    int len;

    len = ft_strlen(c);
    if (len > 0 && c[len - 1] == '\n')
        return (len - 1);
    return (len);
}

void    check_element(t_map *game)
{
    int i;
    int j;

    i = -1;
    param_init(game);
    while (game->map[++i] != NULL)
    {
        j = -1;
        while(game->map[i][++j] != '\0')
        {
            if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P' && game->map[i][j] != '\n')
            {
                write(2, "Error\nInvalid element\n", 22);
                exit(1);
            }
            cnt_element(game->map[i][j], game);
        }
    }
    if (check_cnt(game) == 1)
        exit(1);
}

void    check_dest(t_map *game)
{
    int i;
    int j;

    i = 0;
    check_element(game);
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'P')
            {
                game->dest.x = j;
                game->dest.y = i;
            }
            j++;
        }
        i++;
    }
}

void    param_init(t_map *game)
{
    game->p_cnt = 0;
    game->c_cnt = 0;
    game->e_cnt = 0;
}

void    cnt_element(char  c, t_map *game)
{
    if (c == 'P')
        game->p_cnt++;
    else if (c == 'E')
        game->e_cnt++;
    else if (c == 'C')
        game->c_cnt++;
}

int    check_cnt(t_map *game)
{
    if (game->p_cnt == 1 && game->e_cnt == 1 && game->c_cnt >= 1)
        return (0);
    else
    {
        write(2, "Error\nInvalid character number\n", 32);
        return (1);
    }
}