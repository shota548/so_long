NAME = so_long

# ソースファイル（ft_printfのソースとso_longのソース）
SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

MINILIBX_DIR = ./minilibx-linux

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L$(MINILIBX_DIR) -lmlx -lm -lXext -lX11 -L/usr/X11/lib

CC = gcc
LFLAGS += -lXext -lX11
#↑osによって違うので家でやるときに気をつける（でもwindowsはlinuxと同じそう）

all: $(NAME)

# 実行ファイルをビルド
$(NAME): $(OBJS)
	@echo "Compiling MiniLibX..."
	$(MAKE) -C $(MINILIBX_DIR)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

# オブジェクトファイルをコンパイル
%.o:%.c
	$(CC) $(CFLAGS) -I$(MINILIBX_DIR) -c $< -o $@

.PHONY: clean fclean re

# オブジェクトファイルを削除
clean:
	@echo "Cleaning project..."
	rm -f $(OBJS)
	$(MAKE) -C $(MINILIBX_DIR) clean

# 実行ファイルとオブジェクトファイルを削除
fclean: clean
	@echo "Full cleaning project..."
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) fclean

# クリーンしてから再ビルド
re: fclean all
