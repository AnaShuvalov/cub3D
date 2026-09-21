# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/14 16:54:27 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_PATH = ./MLX42/
MLX_BUILD = $(MLX_PATH)build/
MLX_NAME = libmlx42.a
MLX = $(MLX_BUILD)$(MLX_NAME)

CC = cc
INCLUDES = -Iincludes -Ilibft -Iget_next_line -I$(MLX_PATH)include

BASE_CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)
CFLAGS = $(BASE_CFLAGS)
MLXFLAGS = -L$(MLX_BUILD) -lmlx42 -ldl -lglfw -pthread -lm

PARSER =		srcs/main.c \
				srcs/parser/parser.c \
				srcs/parser/verification_colors.c \
				srcs/parser/verification_map.c \
				srcs/parser/verification_path.c \
				srcs/parser/verification_player.c \
				srcs/parser/all_about_errors.c \
				srcs/parser/grid_building.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
			
RAYCASTER =	

OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	cmake -B $(MLX_BUILD) $(MLX_PATH)
	cmake --build $(MLX_BUILD) -j4

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(MLX_BUILD)

fclean:
	$(RM) $(NAME) $(OBJECTS)
	$(RM) $(MLX_BUILD)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re