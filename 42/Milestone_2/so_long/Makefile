NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mlx -I./get_next_line -I./ft_printf -I./ft_printf/libft

MLX_LIB = ./mlx/libmlx.a
PRINT_LIB = ./ft_printf/libftprintf.a
SRCS = $(GNL_SRCS) map.c main.c error.c img_map.c key.c so_long.c sort.c
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(MLX_LIB):
	$(MAKE) -C ./mlx

$(PRINT_LIB):
	$(MAKE) -C ./ft_printf

$(NAME): $(OBJS) $(MLX_LIB) $(PRINT_LIB)
	$(CC) $(OBJS) $(PRINT_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re