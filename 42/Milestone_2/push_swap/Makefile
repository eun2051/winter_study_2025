NAME= push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = operation.c parse.c push_swap.c error.c op_utils.c \
      print_rotate.c print_op.c \
      move.c cost.c list_a.c target.c sort.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
