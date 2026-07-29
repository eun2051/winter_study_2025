NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = utils.c init.c philo_manager.c status.c clean.c main.c routine_helper.c check_helper.c
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

.PHONY: all clean fclean re
