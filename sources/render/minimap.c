/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/13 13:47:54 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(t_game *game, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;
	int	size;

	size = MINIMAP_MAX_SIZE / game->map.width;
	if (game->map.width < game->map.height)
		size = MINIMAP_MAX_SIZE / game->map.height;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(game->framebuffer, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	get_player(t_game *game, int allignment, int size)
{
	int	player_x;
	int	player_y;
	int	radius;
	int	x;
	int	y;

	radius = MINIMAP_PLAYER_SIZE / 2;
	player_x = (int)(allignment + (game->player.pos_x * size));
	player_y = (int)(PADDING + (game->player.pos_y * size));
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if ((x * x) + (y * y) <= (radius * radius) + 1)
				mlx_put_pixel(game->framebuffer, player_x + x, player_y + y, MINIMAP_PLAYER);
			x++;
		}
		y++;
	}
	x = player_x + (int)round(game->player.dir_x * (MINIMAP_TILE_SIZE / 2));
	y = player_y + (int)round(game->player.dir_y * (MINIMAP_TILE_SIZE / 2));
	mlx_put_pixel(game->framebuffer, x, y, MINIMAP_COMPASS);
}

static uint32_t	get_colors(t_game *game, int col, int row, int len)
{
	uint32_t	color;

	if (col < len && game->map.grid[row][col] == '1')
		color = MINIMAP_WALLS;
	else if (col < len && game->map.grid[row][col] == '0')
		color = MINIMAP_FLOOR;
	else
		color = MINIMAP_SPACE;
	return (color);
}

static void	draw_row_by_row(t_game *game, int row, int allignment, int size)
{
	int			col;
	int			single_row_len;
	uint32_t	color;

	single_row_len = (int)ft_strlen(game->map.grid[row]);
	col = 0;
	while (col < game->map.width)
	{
		color = get_colors(game, col, row, single_row_len);
		draw(game, allignment + (col * size),
			PADDING + (row * size), color);
		col++;
	}
}

void	draw_minimap(t_game *game)
{
	int			row;
	int			size;
	int			allign_right;

	if (game->map.width > MINIMAP_MAX_SIZE
		|| game->map.height > MINIMAP_MAX_SIZE)
		return ;
	size = MINIMAP_MAX_SIZE / game->map.width;
	if (game->map.width < game->map.height)
		size = MINIMAP_MAX_SIZE / game->map.height;
	if (size > MINIMAP_TILE_SIZE)
		size = MINIMAP_TILE_SIZE;
	allign_right = WIN_WIDTH - PADDING - (game->map.width * size);
	if (allign_right < PADDING)
		allign_right = PADDING;
	row = 0;
	while (row < game->map.height)
	{
		draw_row_by_row(game, row, allign_right, size);
		row++;
	}
	get_player(game, allign_right, size);
}
