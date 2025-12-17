# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sramasam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 11:04:05 by sramasam          #+#    #+#              #
#    Updated: 2025/12/17 11:16:48 by sramasam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/get_map.c src/map_utils.c src/check_valid_map.c \
src/setup_window.c src/path_checker.c src/graphic_utils.c \
src/player_movements.c src/main.c src/flood_fill.c
OBJS = $(SRCS:.c=.o)

NAME = so_long
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(LIBFT_DIR)/includes

all: $(NAME)

$(LIBFT):
	$(MAKE) --quiet -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) --quiet -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) --quiet -C $(LIBFT_DIR) clean
	$(MAKE) --quiet -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --quiet -C $(LIBFT_DIR) fclean
	# $(MAKE) --quiet -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft mlx


