# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 21:09:57 by seungele          #+#    #+#              #
#    Updated: 2025/11/07 20:17:28 by seungele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = rcs

SRC1 = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c

SRC2 = ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ1 = $(SRC1:.c=.o) 

OBJ2 = $(SRC2:.c=.o)

OBJB = $(BONUS:.c=.o)

BONUS_MARK = bonus_mark

all: $(NAME)

$(NAME): $(OBJ1) $(OBJ2)
	$(AR) $(ARFLAG) $(NAME) $(OBJ1) $(OBJ2)

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(OBJB)
	$(AR) $(ARFLAG) $(NAME) $(OBJB)
	touch $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ1) $(OBJ2) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS_MARK)

re: fclean $(NAME) $(BONUS_MARK)

.PHONY: all clean fclean re
