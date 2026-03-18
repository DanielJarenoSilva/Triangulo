NAME = cub3D

SRC = $(addprefix src/, main.c print_errors.c libft_utils.c utils.c init.c free.c create_matrix.c check_map.c map_utils.c) \
      $(addprefix src/parse/, parse_errors_1.c parse_utils_1.c parse_utils_2.c parse_utils_3.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c free_buffer.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all