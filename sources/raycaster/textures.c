/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:05:37 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/20 16:23:35 by olmatske         ###   ########.fr       */
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

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	int		i;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (x < 0)
		x = 0;
	if (x >= (int)texture->width)
		x = (int)texture->width - 1;
	if (y < 0)
		y = 0;
	if (y >= (int)texture->height)
		y = (int)texture->height - 1;

	i = (y * (int)texture->width + x) * (int)texture->bytes_per_pixel;
	r = texture->pixels[i + 0];
	g = texture->pixels[i + 1];
	b = texture->pixels[i + 2];
	a = texture->pixels[i + 3];

	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a);
}

mlx_texture_t	*get_texture(t_ray *ray, t_game *game)
{
	mlx_texture_t	*texture;

	if (ray->side == 0) // the ray hit the vertical axis which is left or right side of the wall
	{
		if (ray->step_x > 0)
			texture = game->map.west_texture;
		else
			texture = game->map.east_texture;
	}
	else
	{
		if (ray->step_y > 0)
			texture = game->map.north_texture;
		else
			texture = game->map.south_texture;
	}
	return (texture);
}

// try to make it in one image, one half floor, the other ceiling
void	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(game->background, x, y, game->map.ceiling_color);
			x++;
		}
		y++;
	}
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(game->background, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}

void	clear_framebuffer(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(game->framebuffer, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}