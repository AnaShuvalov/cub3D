# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/14 16:17:56 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -Ilibft -Iget_next_line

BASE_CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)

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

CC = cc

CFLAGS = $(BASE_CFLAGS)

MLX_PATH = ./minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLXFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean:
	$(RM) $(NAME) $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re