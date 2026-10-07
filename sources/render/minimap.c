/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/07 15:43:03 by anshuval         ###   ########.fr       */
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

static void	minimap_compass(mlx_image_t *img, t_game *game, int allignment)
{
	int		x;
	int		y;
	int		dot_x;
	int		dot_y;

	x = (int)(allignment + (game->player.pos_x * MINIMAP_TILE_SIZE));
	y = (int)(PADDING + (game->player.pos_y * MINIMAP_TILE_SIZE));
	dot_x = x + (int)round(game->player.dir_x * MINIMAP_TILE_SIZE);
	dot_y = y + (int)round(game->player.dir_y * MINIMAP_TILE_SIZE);
	draw(img, dot_x, dot_y, MINIMAP_COMPASS);
}

static void	get_player(mlx_image_t *img, t_game *game, int allignment)
{
	int	player_x;
	int	player_y;
	int	x;
	int	y;
	int	radius;

	radius = MINIMAP_PLAYER_SIZE / 2;
	player_x = (int)(allignment + (game->player.pos_x * MINIMAP_TILE_SIZE));
	player_y = (int)(PADDING + (game->player.pos_y * MINIMAP_TILE_SIZE));
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if ((x * x) + (y * y) <= (radius * radius) + 1)
				mlx_put_pixel(img, player_x + x, player_y + y, MINIMAP_PLAYER);
			x++;
		}
		y++;
	}
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

void	draw_map(mlx_image_t *img, t_game *game)
{
	int			row;
	int			col;
	int			len;
	int			allign_right;
	uint32_t	color;

	allign_right = WIN_WIDTH - PADDING - (game->map.width * MINIMAP_TILE_SIZE);
	if (allign_right < PADDING)
		allign_right = PADDING;
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		len = (int)ft_strlen(game->map.grid[row]);
		while (col < game->map.width)
		{
			color = get_colors(game, col, row, len);
			draw(img, allign_right + (col * MINIMAP_TILE_SIZE),
				PADDING + (row * MINIMAP_TILE_SIZE), color);
			col++;
		}
		row++;
	}
	get_player(img, game, allign_right);
	minimap_compass(img, game, allign_right);
}
