/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:56:46 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/25 22:20:34 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAYCAST_H__
#define __RAYCAST_H__

#include "cub3d.h"
#include "MLX42/MLX42.h"

#define TILE 64

#define COLOR_CEILING		0x55e4ffFF
#define COLOR_WALLS			0x895544FF
#define COLOR_FLOOR			0x56db32FF
#define COLOR_PLAYER 		0xcb137fFF

#define	MOVEMENT_SPEED	0.05
#define	ROTATION_SPEED	0.05

typedef struct	s_ray {
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;			// direction of the step
	int		step_y;
	double	side_dist_x;	// distance from the curr position to next x or y grid
	double	side_dist_y;
	double	delta_dist_x;	// distance the ray has to travel across 1 grid unit
	double	delta_dist_y;
	int		wall_hit;
	int		side;			// 0 or 1 depending on W,E,S,N (x and y axis n stuff)
	double	perp_wall_dist;	// perpendicular wall dist to avoid fisheye
	int		line_height;	// height of the wall to draw
	int		draw_start;		// lowest pixel to start drawing
	int		draw_end;		// highest pixel to stop drawing
}	t_ray;


// FUNCTIONS ///////////////////////////////////////////////////////////////////
void	render_frame(void	*param);
void	perform_dda(char **map, t_ray *ray);
void	perform_dda(char **map, t_ray *ray);
void	init_dda_vars(t_ray *ray);
void	draw_wall_slice(t_game *game, t_ray *ray, int x);
void	draw_floor_and_ceiling(t_game *game);
void	direction_handler(t_game *game);
void	clear_framebuffer(t_game *game);

#endif