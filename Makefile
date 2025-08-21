NAME = so_long

SRCS = 	main.c \
		get_next_line.c \
		get_next_line_utils.c \
		read_array_map.c \
		validate_map.c \
		make_image.c \
		move_player.c

OBJS = $(SRCS:%.c=%.o)

MINILIBX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lXext -lX11 -L/usr/X11/lib

CC = gcc

all: $(NAME)

$(NAME): $(MINILIBX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
