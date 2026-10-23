/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:34:13 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/23 16:28:52 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "MLX42/MLX42.h"

# define WIN_WIDTH	1200
# define WIN_HEIGHT	800

# define MINIMAP_MAX_SIZE	 	160
# define MINIMAP_TILE_SIZE 		10
# define MINIMAP_PLAYER_SIZE	4
# define MINIMAP_COMPASS_SIZE	1
# define PADDING 				10

# define MINIMAP_WALLS			0x483329FF
# define MINIMAP_FLOOR			0x3d4a3eFF
# define MINIMAP_PLAYER 		0x39ff14FF
# define MINIMAP_SPACE 			0x666666AA
# define MINIMAP_COMPASS		0xFFFFFFAA
# define MINIMAP_FRAME			0x222222AA

// Key movemment flags - used for smooth wlaking and fluid movement.
// If a key is pressed the bool is set to TRUE. When the key is released,
// 	it is set to false.
// The keys may be pressed for a longer time and simultaneously.
typedef struct s_keys
{
	bool	w; // move forward
	bool	a; // move left
	bool	s; //move backward
	bool	d; // move right
	bool	left; // look left
	bool	right; // look right
}	t_keys;

// Player state for movement and raycasting
// position in grid units (type double - e.g. 4.5), direction and
// plane are vectors
// GRID IS CONSIDERED grid[y][x] where y is row and x is column
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

// Map data from the .cub file 
typedef struct s_map
{
	char			**grid; // 2D grid array, containing 1, 0 and spaces 
	int				width; // max width of the map grid
	int				height; // max height of the map grid
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	long			floor_color; // floor color converted to int (hex format)
	long			ceiling_color; // ceiling color converted to int
	mlx_texture_t	*north_texture; // loaded MLX image for north wall
	mlx_texture_t	*south_texture; // loaded MLX image for south wall
	mlx_texture_t	*west_texture; // loaded MLX image for west wall
	mlx_texture_t	*east_texture; // loaded MLX image for east wall
}	t_map;

typedef struct s_light
{
	double	light_falloff;
	double	min_brightness;
	double	max_brightness;
}	t_light;

// main game struct
typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map; // parsed map with textures and colors
	t_player	player; // player position and direction vectors
	t_keys		key; // current state of the keys
	mlx_image_t	*framebuffer;
	mlx_image_t	*background;
	t_light		light;
}	t_game;

// PARSER /////////////////////
int		parser(int argc, char **argv, t_game *game);
void	free_array(char **array);
void	error_message(char *s);

// RAYCASTER ///////////////////////////////
int		start_game(t_game *game);
int		load_textures(t_map *map);

// HOOKS ////////////////////
void	key_reaction(mlx_key_data_t keydata, void *param);
void	close_game(t_game *game, int exit_status);
void	free_game(t_game *game);
void	close_hook(void *param);

// RENDER ///////////////////
void	render_frame(void *param);
void	draw_minimap(t_game *game);
void	draw_floor_and_ceiling(t_game *game);

#endif
