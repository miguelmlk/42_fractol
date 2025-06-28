NAME = fractol
CFLAGS = -Wall -Wextra -Werror -Imlx -DGL_SILENCE_DEPRECATION -Wno-deprecated-declarations
CC = cc
SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/error.c \
	  $(SRC_DIR)/fractals.c \
	  $(SRC_DIR)/key.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(OBJ_DIR) $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) CFLAGS="-O2 -DGL_SILENCE_DEPRECATION -Wno-deprecated-declarations" MLXFLAGS="-framework OpenGL -framework AppKit"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY:
	all clean fclean re
