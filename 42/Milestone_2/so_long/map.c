#include "so_long.h"

void    read_map(int fd, t_map *game)
{
    int cnt;
    char    *line;

    cnt = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        cnt++;
        free(line);
    }
    close(fd);
    game->map_col = cnt;
}

void    make_map(char *c, t_map *game)
{
    int fd;
    int i;
    int size;
    char    *line;

    if (check_ber(c) == 1)
        exit(1);
    fd = open(c, O_RDONLY);
    read_map(fd, game);
    size = game->map_col;
    fd = open(c, O_RDONLY);
    game->map = (char **)malloc(sizeof(char *) * (size + 1));
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = line;
        i++;
    }
    game->map[size] = NULL;
    close(fd);
    return ;
}

void    print_map(t_map *game)
{
    int i;

    i = 0;
    while (game->map[i] != NULL)
    {
        printf("%s", game->map[i]);
        i++;
    }
}

int    check_ber(char *c)
{
    int size;

    size = ft_strlen(c);
    if (size > 4)
    {
        if (ft_strncmp(c + size - 4, ".ber", 4) != 0)
        {
            write(2, "Error\nInvalid extension\n", 24);
            return (1);
        }
        return (0);
    }
    return (1);
}