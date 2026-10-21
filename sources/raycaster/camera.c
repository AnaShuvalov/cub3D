/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:15:13 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/21 15:46:50 by olmatske         ###   ########.fr       */
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
static void	march_ray(t_game *game, t_ray *ray)
{
	while (ray->wall_hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (hit_wall(&game->map, ray->map_x, ray->map_y))
			ray->wall_hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

static	void	setup_wall_drawing(t_game *game, t_ray *ray)
{
	double			wall_x;
	int				texture_width;
	mlx_texture_t	*texture;

	texture = get_texture(ray, game);
	if (!texture)
		return ;
	texture_width = texture->width;
	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->texture_x = (int)(wall_x * (double)texture_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		ray->texture_x = texture_width - ray->texture_x - 1;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	perform_dda(t_game *game, t_ray *ray)
{
	march_ray(game, ray);
	setup_wall_drawing(game, ray);
}

void	init_dda_vars(t_ray *ray)
{
	ray->perp_wall_dist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_hit = 0;
	ray->side = 0;
	ray->texture_x = 0;
}
