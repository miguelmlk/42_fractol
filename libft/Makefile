NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_memcmp.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c \
ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_putchar_fd.c ft_toupper.c ft_putnbr_fd.c \
get_next_line.c ft_printf_src/ft_print_digit_hex.c \
ft_printf_src/ft_print_digit.c ft_printf_src/ft_print_unsigned_digit.c \
ft_printf_src/ft_printf_char.c ft_printf_src/ft_printf.c \
ft_printf_src/ft_printstring.c ft_printf_src/ft_to_hex.c \
ft_printf_src/ft_voidpointer.c
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f *.o ft_printf_src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

