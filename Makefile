NAME = cub3D

MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

SRC = $(addprefix src/, main.c print_errors.c libft_utils.c utils.c init.c free.c create_matrix.c check_map.c map_utils.c find_player.c cube.c raycast_utils.c raycast.c move.c) \
      $(addprefix src/parse/, parse_errors_1.c parse_utils_1.c parse_utils_2.c parse_utils_3.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c free_buffer.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)/include -g -g3
LDFLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw -ldl -lm -lX11 -lpthread

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build

clean:
	rm -f $(OBJ) $(GNL_OBJ)
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)

re : fclean all