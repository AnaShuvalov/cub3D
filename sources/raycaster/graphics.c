/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:43:39 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/07 17:26:55 by olmatske         ###   ########.fr       */
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

static void	calculate_wall_dimentions(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;

	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	draw_column(t_game *game, t_ray *ray, mlx_texture_t *texture, double brightness, int x)
{
	int				y;
	int				texture_y;
	uint32_t		color;
	double			step;
	double			texture_pos;

	step = 1.0 * texture->height / ray->line_height;
	texture_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture_y = (int)texture_pos % texture->height;
		if (texture_y < 0)
			texture_y += texture->height;
		color = get_texture_pixel(texture, ray->texture_x, texture_y);
		color = darken_color(color, brightness);
		mlx_put_pixel(game->framebuffer, x, y, color);
		texture_pos += step;
		y++;
	}
}

void	draw_wall_slice(t_game *game, t_ray *ray, int x)
{
	mlx_texture_t	*texture;
	double			brightness;

	texture = get_texture(ray, game);
	if (!texture)
		return;
	calculate_wall_dimentions(ray);
	brightness = calculate_brightness(game, ray);
	draw_column(game, ray, texture, brightness, x);

	// y = ray->draw_start;
	// while (y < ray->draw_end)
	// {
	// 	mlx_put_pixel(game->framebuffer, (uint32_t)x, (uint32_t)y, color);
	// 	y++;
	// }
}
