NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mlx_linux -I./get_next_line -I./ft_printf -I./ft_printf/libft

MLX_LIB = ./mlx_linux/libmlx.a
PRINT_LIB = ./ft_printf/libftprintf.a
SRCS = $(GNL_SRCS) element.c error.c img_map.c key.c map.c sort.c free.c so_long.c
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(MLX_LIB):
	$(MAKE) -C ./mlx_linux

$(PRINT_LIB):
	$(MAKE) -C ./ft_printf

$(NAME): $(OBJS) $(MLX_LIB) $(PRINT_LIB)
	$(CC) $(OBJS) -Lmlx_linux -lmlx $(PRINT_LIB) -lXext -lX11 -lm -o $(NAME)
# 	$(CC) $(OBJS) $(PRINT_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C ./mlx_linux clean
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
