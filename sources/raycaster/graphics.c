/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:43:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/25 16:02:52 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static double	calculate_brightness(t_game *game, t_ray *ray)
{
	double	brightness;
	double	distance_factor;

	distance_factor = 1.0 + (ray->perp_wall_dist * game->light.light_falloff);
	brightness = game->light.max_brightness / distance_factor;

	if (brightness < game->light.min_brightness)
		brightness = game->light.min_brightness;

	return (brightness);
}

static	uint32_t	darken_color(uint32_t color, double	brightness)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;

	r = (int)(r * brightness);
	g = (int)(g * brightness);
	b = (int)(b * brightness);

	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a);
}

void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	int			y;
	uint32_t	color;
	double		brightness;

	color = COLOR_WALLS;

	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;

	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;

	brightness = calculate_brightness(game, ray);
	color = darken_color(COLOR_WALLS, brightness);

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		mlx_put_pixel(game->framebuffer, (uint32_t)x, (uint32_t)y, color);
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
		while (WIN_WIDTH)
		{
			mlx_put_pixel(game->framebuffer, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
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
			mlx_put_pixel(game->background, x, y, COLOR_CEILING);
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
			mlx_put_pixel(game->background, x, y, COLOR_FLOOR);
			x++;
		}
		y++;
	}
}
