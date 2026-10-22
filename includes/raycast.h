/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:56:46 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/22 11:33:37 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"
# include "MLX42/MLX42.h"
// #include <sys/time.h>	// for fps

# define TILE 64
# define PLAYER_RADIUS 0.03

# define MOVEMENT_SPEED	3
# define ROTATION_SPEED	4

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;			// direction of the step
	int		step_y;
	double	side_dist_x;	// distance from the curr position to next x or y
	double	side_dist_y;
	double	delta_dist_x;	// distance the ray has to travel across 1 grid unit
	double	delta_dist_y;
	int		wall_hit;
	int		side;			// 0 or 1 depending on W,E,S,N (x & y axis n stuff)
	double	perp_wall_dist;	// perpendicular wall dist to avoid fisheye
	int		line_height;	// height of the wall to draw
	int		draw_start;		// lowest pixel to start drawing
	int		draw_end;		// highest pixel to stop drawing
	int		texture_x;
	t_game	*game;
}	t_ray;

// FUNCTIONS ///////////////////////////////////////////////////////////////////
void			render_frame(void	*param);
void			perform_dda(t_game *game, t_ray *ray);
void			init_dda_vars(t_ray *ray);
void			draw_wall_slice(t_game *game, t_ray *ray, int x);
void			draw_floor_and_ceiling(t_game *game);
void			direction_handler(t_game *game);
void			clear_framebuffer(t_game *game);
uint32_t		get_wall_color(t_ray *ray);
int				load_textures(t_map *map);
mlx_texture_t	*get_texture(t_ray *ray, t_game *game);
uint32_t		get_texture_pixel(mlx_texture_t *texture, int x, int y);

// BONUS /////////////////////////////////////////////////////////////////////
void			bonus_handler(t_game *game)
void			bonus_rotate_player(t_player *player, double angle);
void			bonus_walk_forward_backward(t_game *game);
void			bonus_strafe_left_right(t_game *game);

#endif