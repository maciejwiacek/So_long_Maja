NAME = so_long

SRCS = parse_map.c \
	main.c \
	validate_map/validate_map.c \
	validate_map/check_borders.c \
	validate_map/check_chars.c \
	validate_map/check_collectibles.c \
	validate_map/check_exit.c \
	validate_map/check_if_rectangular.c \
	validate_map/check_start.c \
	validate_utils/len_without_newline.c \
	validate_utils/error_handling.c \
	validate_utils/map_height.c \
	validate_utils/free_map.c \
	validate_utils/map_width.c \
	flood_fill.c \
	close_game.c \
	events.c \
	fill_texture.c \
	start_game.c \

MLX = minilibx-linux/

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: clone $(NAME)

clone:
	if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi

$(NAME): $(OBJS)
	make -C my_lib
	make -C minilibx-linux
	$(CC) $(OBJS) my_lib/my_lib.a -L$(MLX) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)

clean:
	make clean -C my_lib
	$(RM) $(OBJS)
	make clean -C minilibx-linux

fclean:	clean
	$(RM) $(NAME)
	rm -rf my_lib/my_lib.a
	rm -rf minilibx-linux

re: fclean all

.PHONY: all clean fclean re
