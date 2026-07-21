NAME1 = client
NAME2 = server

CC = cc

CFLAG1 = -Wall -Werror -Wextra 
CFLAG2 = -L$(LIBFT_DIR) -lft

LIBFT_DIR = ../
LIBFT = $(LIBFT_DIR)/libft.a

SRC1 = client.c
SRC2 = server.c
OBJ_SRC1 = $(SRC1:.c=.o)
OBJ_SRC2 = $(SRC2:.c=.o)

B_SRC1 = client_bonus.c
B_SRC2 = server_bonus.c
OBJ_B_SRC1 = $(B_SRC1:.c=.o)
OBJ_B_SRC2 = $(B_SRC2:.c=.o)

BONUS_MARK = bonus_mark

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_SRC1) $(LIBFT)
	$(CC) $(CFLAG1) $(OBJ_SRC1) $(CFLAG2) -o $@
$(NAME2): $(OBJ_SRC2) $(LIBFT)
	$(CC) $(CLFAG1) $(OBJ_SRC2) $(CFLAG2) -o $@

$.o: %.c
	$(CC) $(CFLAG1) -c $< -o $@

bonus: $(BONUS_MARK)
	
$(BONUS_MARK):	$(B_SRC1) $(B_SRC2)
		make -C $(LIBFT_DIR) bonus
		$(CC) $(CFLAG1) -c $(B_SRC1) $(CFLAG2) -o $(OBJ_B_SRC1)
		$(CC) $(CFLAG2) -c $(B_SRC2) $(CFLAG2) -o $(OBJ_B_SRC2)
		$(all)
		touch $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_SRC1) $(OBJ_SRC2) $(OBJ_B_SRC1) $(OBJ_B_SRC2) $(BONUS_MARK)
	
fclean: clean
	rm -rf $(NAME1) $(NAME2)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re fclean clean all bonus
