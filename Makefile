# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/21 14:51:56 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NEW MAKEFILE WITH WORKING MLX LINKING

NAME = cub3d

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX42 paths
MLX_DIR = ./MLX42
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

BASE_CFLAGS = -Wall -Werror -Wextra -g3

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
			
RAYCASTER =		raycaster/raymain.c

OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

CC = cc

# SANITIZE_FLAGS = -fsanitize=address -fno-omit-frame-pointer -fsanitize-recover=all
# $(SANITIZE_FLAGS)

CFLAGS = $(BASE_CFLAGS) $(MLX_INC)

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
	$(RM) $(MLX_BUILD)

fclean:
	$(RM) $(NAME) $(OBJECTS)
	$(RM) $(MLX_BUILD)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re


# OLD MAKEFILE FOR PRESERVATION

# NAME = cub3d
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a
# BASE_CFLAGS = -Wall -Werror -Wextra -g3

# PARSER =		main.c \
# 				parser/parser.c \
# 				parser/verification_colors.c \
# 				parser/verification_data.c \
# 				parser/verification_map.c \
# 				parser/verification_path.c \
# 				parser/verification_player.c \
# 				parser/parser_helpers.c \
# 				parser/all_about_errors.c \
# 				parser/endgame.c \
# 				get_next_line/get_next_line.c \
# 				get_next_line/get_next_line_utils.c \
			
# RAYCASTER =		raycaster/raymain.c

# OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

# CC = cc

# CFLAGS = $(BASE_CFLAGS)

# MLX_PATH = ./minilibx-linux/

# MLX_NAME = libmlx.a

# MLX = $(MLX_PATH)$(MLX_NAME)

# MLXFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

# RM = rm -rf

# all: $(NAME)

# $(NAME): $(OBJECTS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RM) $(OBJECTS)

# fclean:
# fclean:
# 	$(RM) $(NAME) $(OBJECTS)
# 	$(MAKE) -C $(LIBFT_DIR) fclean

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# .PHONY: all clean fclean re