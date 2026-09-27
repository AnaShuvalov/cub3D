/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:15:13 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/26 23:59:18 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	hit_wall(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return (1);
	if (!map->grid[y] || x >= (int)ft_strlen(map->grid[y]))
		return (1);
	return (map->grid[y][x] != '0');
}

// DDA stands for Digital Differential Analysis
void	perform_dda(t_game *game, t_ray *ray)
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
		if (hit_wall(&game->map, ray->map_x, ray->map_y))
			ray->wall_hit = 1;
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
