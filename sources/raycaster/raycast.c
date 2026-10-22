/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:15:09 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/22 16:48:03 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// Calculates ray's direction based on which column we're drawing
static void	init_ray_direction(t_ray *ray, t_player *player, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
}

// 1e30 is 1 times 10^30 because otherwise it'd go to infinity
// which we can't use in calulation here. Large enough to never
// cause problems, small enough to not overflow
// fabs stands for "floating-point absolute value", basically from
// -1 to (+)1 etc
//
// Calculates how far ray travels to cross one cell
static void	init_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

// calculates the x axis step dir and dis to first x gird line
static void	init_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static void	init_ray(t_game *game, t_ray *ray, t_player *player, int x)
{
	init_ray_direction(ray, player, x);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	init_delta_dist(ray);
	init_step(ray, player);
	ray->wall_hit = 0;
	ray->game = game;
}

void	render_frame(void	*param)
{
	t_game	*game;
	t_ray	ray;
	int		x;

	game = (t_game *)param;
	x = 0;
	direction_handler(game);
	clear_framebuffer(game);
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, &game->player, x);
		perform_dda(game, &ray);
		draw_wall_slice(game, &ray, x);
		x++;
	}
}
