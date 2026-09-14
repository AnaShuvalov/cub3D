##############################################
#                                            #
#          temporary makefile                #
#                                            #
##############################################

NAME        = ray
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRC         = raymain.c
OBJ         = $(SRC:.c=.o)

# MLX42 specific paths and flags
MLX_DIR     = ../AAAAAAA/include/MLX42
MLX_INC     = -I$(MLX_DIR)/include
MLX_LIB = -L../AAAAAAA/build -lmlx42 -lglfw -ldl -lGL -lm -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
