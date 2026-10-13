/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:34:13 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/13 13:46:25 by anshuval         ###   ########.fr       */
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

# define COLOR_CEILING			0x55e4ffFF
# define COLOR_WALLS			0x895544FF
# define COLOR_FLOOR			0x56db32FF
# define COLOR_PLAYER 			0xcb137fFF

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
// position in grid units (type double - e.g. 4.5), direction and plane are vectors
// GRID IS CONSIDERED grid[y][x] where y is row and x is column
typedef struct s_player
{
	double	pos_x; // player's horisontal position on the grid. 5.5 means the middle of tile 5
	double	pos_y; // player's vertical position on the grid
	double	dir_x; // direction of the player's view - where east is 1.0 and west is -1.0
	double	dir_y; // direction of the player's view - where south is 1.0 and north is -1.0
	double	plane_x; // determines the field of view of the player on the x axis. is perpendicular to the direction vector
	double	plane_y; // determines the field of view of the player on the y axis. is perpendicular to the direction vector
}	t_player;

// Map data from the .cub file 
typedef struct s_map
{
	char	**grid; // 2D grid array, containing 1, 0 and spaces 
	int		width; // max width of the map grid
	int		height; // max height of the map grid
	char	*north_texture_path; // path to north texture from the .cub file
	char	*south_texture_path; // path to south texture from the .cub file
	char	*west_texture_path; // path to west texture from the .cub file
	char	*east_texture_path; // path to east texture from the .cub file
	long	floor_color; // floor color converted to int (hex format)
	long	ceiling_color; // ceiling color converted to int (hex format)
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
void	render_frame(void	*param);
int		start_game(t_game *game);
int		load_textures(t_map *map);

// HOOKS ////////////////////
void	key_reaction(mlx_key_data_t keydata, void *param);
void	close_game(t_game *game);
void	free_game(t_game *game);
void	close_hook(void *param);
void	exit_on_error(t_game *game, char *s);

// RENDER ///////////////////
void	render_frame(void *param);
void	draw_minimap(t_game *game);
void	draw_floor_and_ceiling(t_game *game);

#endif
