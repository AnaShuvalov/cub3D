/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:05:37 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/07 13:28:52 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	load_textures(t_map *map)
{
	map->north_texture = mlx_load_png(map->north_texture_path);
	if (!map->north_texture)
		return(1);
	map->south_texture = mlx_load_png(map->south_texture_path);
	if (!map->south_texture)
		return(1);
	map->east_texture = mlx_load_png(map->east_texture_path);
	if (!map->east_texture)
		return(1);
	map->west_texture = mlx_load_png(map->west_texture_path);
	if (!map->west_texture)
		return(1);
	return (0);
}

uint32_t	get_texture(t_ray *ray, t_game *game)
{
	uint32_t	texture;

	if (ray->side == 0) // the ray hit the vertical axis which is left or right side of the wall
	{
		if (ray->step_x > 0)
			texture = game->map.texture_west;
		else
			texture = game->map.texture_east;
	}
	else
	{
		if (ray->step_y > 0)
			texture = game->map.texture_north;
		else
			texture = game->map.texture_south;
	}
	return (texture);
}

