# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/08/24 15:45:26 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
BASE_CFLAGS = -Wall -Werror -Wextra -g3

PARSER =	
			
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
fclean:
	$(RM) $(NAME) $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re