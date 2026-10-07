/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/07 14:25:50 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw(mlx_image_t *img, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;
	int	size;

	if (color == MINIMAP_PLAYER)
		size = MINIMAP_PLAYER_SIZE;
	else if (color == MINIMAP_COMPASS)
		size = MINIMAP_COMPASS_SIZE;
	else
		size = MINIMAP_TILE_SIZE;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (start_x + x >= 0 && start_y + y >= 0
				&& start_x + x < WIN_WIDTH && start_y + y < WIN_HEIGHT)
				mlx_put_pixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	minimap_compass(mlx_image_t *img, t_game *game, int allignment)
{
	int	dot_x;
	int	dot_y;

	dot_x = (int)(allignment + ((game->player.pos_x + game->player.dir_x)
				* MINIMAP_TILE_SIZE)) - 1;
	dot_y = (int)(PADDING + ((game->player.pos_y + game->player.dir_y)
				* MINIMAP_TILE_SIZE)) - 1;
	draw(img, dot_x, dot_y, MINIMAP_COMPASS);
}

static void	get_player(mlx_image_t *img, t_game *game, int allignment)
{
	int	player_x;
	int	player_y;

	player_x = (int)(allignment + (game->player.pos_x * MINIMAP_TILE_SIZE))
		- (MINIMAP_PLAYER_SIZE / 2);
	player_y = (int)(PADDING + (game->player.pos_y * MINIMAP_TILE_SIZE))
		- (MINIMAP_PLAYER_SIZE / 2);
	draw(img, player_x, player_y, MINIMAP_PLAYER);
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
