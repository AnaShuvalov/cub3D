/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/13 11:25:39 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(mlx_image_t *img, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;
	int	size;

	if (color == MINIMAP_COMPASS)
		size = MINIMAP_COMPASS_SIZE;
	else
		size = MINIMAP_TILE_SIZE;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	player_with_compass(mlx_image_t *img, t_game *game, int center_x, int center_y)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;
	int	radius;

	radius = MINIMAP_PLAYER_SIZE / 2;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if ((x * x) + (y * y) <= (radius * radius) + 1)
				mlx_put_pixel(img, center_x + x, center_y + y, MINIMAP_PLAYER);
			x++;
		}
		y++;
	}
	player_x = center_x + (int)round(game->player.dir_x * MINIMAP_TILE_SIZE);
	player_y = center_y + (int)round(game->player.dir_y * MINIMAP_TILE_SIZE);
	draw(img, player_x, player_y, MINIMAP_COMPASS);
}

static uint32_t	get_colors(t_game *game, int col, int row)
{
	uint32_t	color;

	if (row < 0 || row >= game->map.height || game->map.grid[row] == NULL
			|| col < 0 || col >= (int)ft_strlen(game->map.grid[row]))
		color = MINIMAP_SPACE;
	else if (game->map.grid[row][col] == '1')
		color = MINIMAP_WALLS;
	else if (game->map.grid[row][col] == '0')
		color = MINIMAP_FLOOR;
	else
		color = MINIMAP_SPACE;
	return (color);
}

static void	draw_row_by_row(mlx_image_t *img, t_game *game, int row, int allign_right)
{
	int			col;
	int			start_x;
	int			start_y;
	uint32_t	color;

	start_x = (int)game->player.pos_x - (MINIMAP_SIZE / 2);
	start_y = (int)game->player.pos_y - (MINIMAP_SIZE / 2);
	col = 0;
	while (col < MINIMAP_SIZE)
	{
		color = get_colors(game, start_x + col, start_y + row);
		draw(img, allign_right + (col * MINIMAP_TILE_SIZE),
			PADDING + (row * MINIMAP_TILE_SIZE), color);
		col++;
	}
}

void	draw_minimap(mlx_image_t *img, t_game *game)
{
	int	row;
	int	allign_right;
	int	center_x;
	int	center_y;

	allign_right = WIN_WIDTH - PADDING - (MINIMAP_SIZE * MINIMAP_TILE_SIZE);
	if (allign_right < PADDING)
		allign_right = PADDING;
	row = 0;
	while (row < MINIMAP_SIZE)
	{
		draw_row_by_row(img, game, row, allign_right);
		row++;
	}
	center_x = allign_right + (MINIMAP_SIZE * MINIMAP_TILE_SIZE) / 2
		+ (int)((game->player.pos_x - (int)game->player.pos_x - 0.5) * MINIMAP_TILE_SIZE);
	center_y = PADDING + (MINIMAP_SIZE * MINIMAP_TILE_SIZE) / 2
		+ (int)((game->player.pos_y - (int)game->player.pos_y - 0.5) * MINIMAP_TILE_SIZE);
	player_with_compass(img, game, center_x, center_y);
}
