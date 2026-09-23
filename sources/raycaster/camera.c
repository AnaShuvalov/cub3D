/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:15:13 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/23 12:22:18 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// DDA stands for Digital Differential Analysis
void	perform_dda(char **map, t_ray *ray)
{
	while (ray->wall_hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // hit x axis
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // hit y axis
		}
		if (map[ray->map_y][ray->map_x] > '0')
			ray->wall_hit = 1;
		if (ray->map_y < 0 || ray->map_x < 0)
			break;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	init_dda_vars(t_ray *ray)
{
	ray->perp_wall_dist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_hit = 0;
	ray->side = 0;
}

void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	int			y;
	uint32_t		color;

	color = COLOR_WALLS;

	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;

	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;

	y = ray->draw_start;
	while (y >= ray->draw_start && y < ray->draw_end)
	{
		mlx_put_pixel(game->framebuffer, (uint32_t)x, (uint32_t)y, color);
		y++;
	}
}
