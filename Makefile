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

# ==============================================================================
# 1. GLOBAL SETTINGS & COLORS (Added for clean terminal output)
# ==============================================================================
MAKEFLAGS += --silent --no-print-directory

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

# ==============================================================================
# 2. OS DETECTION & FLAGS
# ==============================================================================
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
			
RAYCASTER =		sources/raycaster/raymain.c
OBJECTS = $(PARSER:.c=.o) $(RAYCASTER:.c=.o)

CC = cc
RM = rm -rf

# ==============================================================================
# 3. TARGETS
# ==============================================================================
all: $(NAME)

# --- Final Linking ---
$(NAME): $(OBJECTS) $(LIBFT) $(MLX_LIB)
	@printf "$(YELLOW)⠋$(NC) Linking $(NAME)...%30s\r" ""
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) >/dev/null 2>&1 && \
		printf "$(GREEN)✔$(NC) Linked $(NAME) successfully!%12s\n" "" || \
		(printf "\n$(RED)✖ ERROR linking $(NAME)$(NC)\n" && exit 1)

# --- Libft Build ---
$(LIBFT):
	@printf "$(YELLOW)⠋$(NC) Building libft...%30s\r" ""
	@$(MAKE) -s -C $(LIBFT_DIR) >/dev/null 2>&1 && \
		printf "$(GREEN)✔$(NC) Built libft successfully%16s\n" "" || \
		(printf "\n$(RED)✖ ERROR building libft$(NC)\n" && exit 1)

# --- MLX42 Build ---
$(MLX_LIB):
	@printf "$(YELLOW)⠋$(NC) Configuring MLX42...%26s\r" ""
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build >/dev/null 2>&1 && \
		printf "$(GREEN)✔$(NC) Configured MLX42%30s\n" "" || \
		(printf "\n$(RED)✖ ERROR configuring MLX42$(NC)\n" && exit 1)
	@printf "$(YELLOW)⠋$(NC) Compiling MLX42...%28s\r" ""
	@$(MAKE) -s -C $(MLX_DIR)/build >/dev/null 2>&1 && \
		printf "$(GREEN)✔$(NC) Compiled MLX42%32s\n" "" || \
		(printf "\n$(RED)✖ ERROR compiling MLX42$(NC)\n" && exit 1)

# --- C to Object Compilation (The main source of clutter) ---
%.o: %.c 
	@printf "$(YELLOW)⠋$(NC) Compiling: %-35s\r" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1 && \
		printf "$(GREEN)✔$(NC) Compiled:  %-35s\n" "$<" || \
		(printf "\n$(RED)✖ ERROR compiling: %s$(NC)\n" "$<" && exit 1)

# --- Cleanup ---
clean:
	@printf "$(YELLOW)⠋$(NC) Cleaning object files...%20s\r" ""
	@$(RM) $(OBJECTS)
	@$(RM) $(MLX_DIR)/build
	@printf "$(GREEN)✔$(NC) Cleaned object files%26s\n" ""

fclean: clean
	@printf "$(YELLOW)⠋$(NC) Removing $(NAME) and libft...%14s\r" ""
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@printf "$(GREEN)✔$(NC) Full clean complete%27s\n" ""

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



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
