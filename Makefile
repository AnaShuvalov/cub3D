# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/24 15:30:27 by anshuval          #+#    #+#              #
#    Updated: 2026/09/23 19:44:44 by anshuval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NEW MAKEFILE WITH WORKING MLX LINKING

MAKEFLAGS += --no-print-directory

GREEN 	:= \033[0;32m
RED   	:= \033[0;31m
YELLOW	:= \033[0;33m
B_CYAN	:= \033[1;36m
MAGENTA	:= \033[0;35m
NC    	:= \033[0m

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
				sources/raycaster/camera.c \
				sources/raycaster/graphics.c



HOOKS =			sources/hooks/key_events.c \
				sources/hooks/close_events.c

RENDER =		sources/render/frame.c \
				sources/render/minimap.c

SRCS = $(PARSER) $(RAYCASTER) $(HOOKS) $(RENDER)

OBJ_DIR = obj
OBJECTS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = cc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX_LIB)
	@printf "$(YELLOW)⠋$(NC) Linking $(NAME)...\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)✔$(NC) $(NAME) built successfully!\n"
	@printf "$(MAGENTA)▶$(NC) You can now start the game: $(B_CYAN)./cub3d maps/(in)valid/map.cub$(NC)\n"

$(LIBFT):
	@printf "$(YELLOW)⠋$(NC) Building libft...\n"
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX_LIB):
	@printf "$(YELLOW)⠋$(NC) Configuring MLX42...\n"
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null 2>&1
	@printf "$(YELLOW)⠋$(NC) Compiling MLX42...\n"
	@$(MAKE) -C $(MLX_DIR)/build > /dev/null 2>&1

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(YELLOW)⠋$(NC) Cleaning object files...\n"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(MLX_DIR)/build
	@printf "$(GREEN)✔$(NC) Object files cleaned!\n"

fclean: clean
	@printf "$(YELLOW)⠋$(NC) Removing $(NAME) and libft...\n"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@printf "$(GREEN)✔$(NC) $(NAME) and libft cleaned!\n"
	@printf "$(B_CYAN)✷$(NC) Full clean complete!\n"

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
