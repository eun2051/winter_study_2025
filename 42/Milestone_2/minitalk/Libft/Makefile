CC = cc 
CFLAGS = -Wall -Wextra -Werror -fPIC
AR = ar
AR_FLAGS = -rcs
NAME = libft.a
SRCS_LIBFT_PART1 = ./ft_isalpha.c \
       ./ft_isdigit.c \
       ./ft_isalnum.c \
       ./ft_isascii.c \
       ./ft_isprint.c \
       ./ft_strlen.c \
       ./ft_memset.c \
       ./ft_bzero.c \
       ./ft_memcpy.c \
       ./ft_memmove.c \
       ./ft_strlcpy.c \
       ./ft_strlcat.c \
       ./ft_toupper.c \
       ./ft_tolower.c \
       ./ft_strchr.c \
       ./ft_strrchr.c \
       ./ft_strncmp.c \
       ./ft_memchr.c \
       ./ft_memcmp.c \
       ./ft_strnstr.c \
       ./ft_atoi.c \
       ./ft_calloc.c \
       ./ft_strdup.c

SRCS_LIBFT_PART2 = ./ft_substr.c \
	     ./ft_strjoin.c \
	     ./ft_strtrim.c \
	     ./ft_split.c \
	     ./ft_itoa.c \
	     ./ft_strmapi.c \
	     ./ft_striteri.c \
	     ./ft_putchar_fd.c \
	     ./ft_putstr_fd.c \
	     ./ft_putendl_fd.c \
	     ./ft_putnbr_fd.c

SRCS_LIBFT_BONUS = ./ft_lstnew_bonus.c \
	     ./ft_lstadd_front_bonus.c \
	     ./ft_lstsize_bonus.c \
	     ./ft_lstlast_bonus.c \
	     ./ft_lstadd_back_bonus.c \
	     ./ft_lstdelone_bonus.c \
	     ./ft_lstclear_bonus.c \
	     ./ft_lstiter_bonus.c \
	     ./ft_lstmap_bonus.c

LIBFT_BONUS_MARK = libft_bonus_mark

FT_PRINTF = ./ft_printf.c \
		./functions/ft_printf_dec.c \
		./functions/ft_printf_char.c \
		./functions/ft_printf_format.c \
		./functions/ft_printf_hex.c \
		./functions/ft_printf_pointer.c \
		./functions/ft_printf_str.c \
		./functions/ft_printf_uint.c \
		./functions/putnbr_base.c
		
HEADER = ./libft.h ./ft_printf.h

OBJS_LIBFT_PART1 = $(SRCS_LIBFT_PART1:.c=.o)
OBJS_LIBFT_PART2 = $(SRCS_LIBFT_PART2:.c=.o)
OBJS_LIBFT_BONUS = $(SRCS_LIBFT_BONUS:.c=.o)
OBJS_PRINTF = $(FT_PRINTF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_LIBFT_PART1) $(OBJS_LIBFT_PART2) $(OBJS_PRINTF)
	   $(AR) $(AR_FLAGS) $(NAME) $(OBJS_LIBFT_PART1) $(OBJS_LIBFT_PART2) $(OBJS_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS_LIBFT_PART1) $(OBJS_LIBFT_PART2) $(OBJS_LIBFT_BONUS) $(OBJS_PRINTF)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(LIBFT_BONUS_MARK)

$(LIBFT_BONUS_MARK): $(OBJS_LIBFT_BONUS) $(OBJS_LIBFT_PART1) $(OBJS_LIBFT_PART2) $(OBJS_PRINTF)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS_LIBFT_PART1) $(OBJS_LIBFT_PART2) $(OBJS_LIBFT_BONUS) $(OBJS_PRINTF)
	touch $@
	
.PHONY: re clean fclean all
