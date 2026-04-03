/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:12:14 by seungele          #+#    #+#             */
/*   Updated: 2026/03/13 16:10:54 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC    65307  //53
# define W      119  //13
# define A      97  //1
# define S      115  //0
# define D      100  //2

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx_linux/mlx.h"
# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_img {
	void	*player;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_win;

typedef struct s_cor {
	int	x;
	int	y;
}	t_cor;

typedef struct s_map {
	int		move_cnt;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		map_col;
	int		map_row;
	char	**copy;
	char	**map;
	t_cor	dest;
	t_win	mlx;
}	t_map;

int		check_cnt(t_map *game);
int		check_ber(char *c);
int		get_len(char *c);
int		check_cnt(t_map *game);
int		close_map(void);
int		key_press(int keycode, t_map *game);
void	check_element(char c);
void	read_map(int fd, t_map *game);
void	make_map(char *c, t_map *game);
void	is_wall(t_map *game);
void	is_rectangle(t_map *game);
void	check_dest(t_map *game);
void	param_init(t_map *game);
void	img_map(t_map *game);
void	put_img(t_map *game);
void	check_player(t_map *game, int x, int y);
void	draw_element(t_map *game, int i, int j);
void	valid_element(t_map *game, char c);
void	check_error(t_map *game);
void	copy_map(t_map *game);
void	free_copy(char **c);
void	valid_map(t_map *game);
void	flood_fill(t_map *game, int x, int y);

#endif
