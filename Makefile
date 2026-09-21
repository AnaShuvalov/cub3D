# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/21 15:12:53 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NEW MAKEFILE WITH WORKING MLX LINKING

NAME = cub3d

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX42 paths
MLX_DIR = ./includes/MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = -I$(MLX_DIR)/include

# /////////////////////////////////////////////////////////////////////////////////////////////////
#		EXPLANATION FOR THE OS DETECTION
#
#	• 'uname -s' is the shell command to detect the operating system name (for MacOS it's Darwin)
#	• $(shell ...) performs a shell command and stores it's output in the UNAME_S variable
#	• ifeq (A, B) is a conditional saying "if A equals B perform the following action", like if 
#		but shorter
#	• endif closes the block and is playing the role of a closing curly bracket '}', since
#		Makefiles don't use those
#	
# /////////////////////////////////////////////////////////////////////////////////////////////////

# OS detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
# macOS specific MLX42 flags
	MLX_FLAGS = -L$(MLX_DIR)/build -L/opt/homebrew/lib -lmlx42 -lglfw3 \
				-framework OpenGL -framework AppKit \
				-framework IOKit -framework CoreFoundation \
				-framework Metal -framework QuartzCore
else
# Linux specific MLX42 flags
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw \
				-ldl -lGL -lm -lpthread
endif

INCLUDES = -Iincludes -I$(LIBFT_DIR) -Iincludes/get_next_line

BASE_CFLAGS = -Wall -Werror -Wextra -g3

PARSER =		sources/main.c \
				sources/parser/parser.c \
				sources/parser/verification_colors.c \
				sources/parser/verification_map.c \
				sources/parser/verification_path.c \
				sources/parser/verification_player.c \
				sources/parser/all_about_errors.c \
				sources/parser/grid_building.c \
				includes/get_next_line/get_next_line.c \
				includes/get_next_line/get_next_line_utils.c \
			
RAYCASTER =		sources/raycaster/raymain.c

OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

CC = cc

# SANITIZE_FLAGS = -fsanitize=address -fno-omit-frame-pointer -fsanitize-recover=all
# $(SANITIZE_FLAGS)

CFLAGS = $(BASE_CFLAGS) $(INCLUDES) $(MLX_INC)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS)  $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build -j4

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(MLX_DIR)/build

fclean:
	$(RM) $(NAME) $(OBJECTS)
	$(RM) $(MLX_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
