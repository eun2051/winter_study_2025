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

void	check_element(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
	{
		write(2, "Error\nInvalid element\n", 22);
		exit(1);
	}
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
			check_element(game->map[i][j]);
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
		exit(1);
}

void	param_init(t_map *game)
{
	game->p_cnt = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
}

int	check_cnt(t_map *game)
{
	if (game->p_cnt == 1 && game->e_cnt == 1 && game->c_cnt >= 1)
		return (0);
	else
	{
		write(2, "Error\nInvalid character number\n", 32);
		return (1);
	}
}
