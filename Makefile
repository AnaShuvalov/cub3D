# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/22 14:22:43 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NEW MAKEFILE WITH WORKING MLX LINKING

MAKEFLAGS += --no-print-directory

GREEN := \033[0;32m
RED   := \033[0;31m
YELLOW:= \033[0;33m
NC    := \033[0m

NAME = cub3d

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./includes/MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = -I$(MLX_DIR)/include

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L$(MLX_DIR)/build -L/opt/homebrew/lib -lmlx42 -lglfw3 \
				-framework OpenGL -framework AppKit \
				-framework IOKit -framework CoreFoundation \
				-framework Metal -framework QuartzCore
else
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw \
				-ldl -lGL -lm -lpthread
endif

INCLUDES = -Iincludes -I$(LIBFT_DIR) -Iincludes/get_next_line
BASE_CFLAGS = -Wall -Werror -Wextra -g3
CFLAGS = $(BASE_CFLAGS) $(INCLUDES) $(MLX_INC)

PARSER =		sources/main.c \
				sources/parser/parser.c \
				sources/parser/verification_colors.c \
				sources/parser/verification_map.c \
				sources/parser/verification_path.c \
				sources/parser/verification_player.c \
				sources/parser/all_about_errors.c \
				sources/parser/grid_building.c \
				includes/get_next_line/get_next_line.c \
				includes/get_next_line/get_next_line_utils.c
			
RAYCASTER =		sources/raycaster/raymain.c \
				sources/raycaster/raycast.c \
				sources/raycaster/camera.c


OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

CC = cc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX_LIB)
	@printf "$(YELLOW)⠋$(NC) Linking $(NAME)...\n"
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@printf "$(YELLOW)⠋$(NC) Building libft...\n"
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@printf "$(YELLOW)⠋$(NC) Configuring MLX42...\n"
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@printf "$(YELLOW)⠋$(NC) Compiling MLX42...\n"
	$(MAKE) -C $(MLX_DIR)/build

%.o: %.c 
	@printf "$(YELLOW)⠋$(NC) Compiling: %s\n" "$<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(YELLOW)⠋$(NC) Cleaning object files...\n"
	$(RM) $(OBJECTS)
	$(RM) $(MLX_DIR)/build
	@printf "$(GREEN)✔$(NC) Cleaned object files\n"

fclean: clean
	@printf "$(YELLOW)⠋$(NC) Removing $(NAME) and libft...\n"
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)✔$(NC) Full clean complete\n"

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re



# /////////////////////////////////////////////////////////////////////////////////////////////////
#		EXPLANATION FOR THE OS DETECTION
#
#	• 'uname -s' is the shell command to detect the operating system name (for MacOS it's Darwin)
#	• $(shell ...) performs a shell command and stores it's output in the UNAME_S variable
#	• ifeq (A, B) is a conditional saying "if A equals B perform the following action", like the if
#		condition but shorter
#	• endif closes the block and is playing the role of a closing curly bracket '}', since
#		Makefiles don't use those
#	
# /////////////////////////////////////////////////////////////////////////////////////////////////
