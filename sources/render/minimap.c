/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 19:50:33 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static minimap_compass(mlx_image_t *img, t_game *game)
{
	
}

static void	minimap(mlx_image_t *img, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_TILE)
	{
		x = 0;
		while (x < MINIMAP_TILE)
		{
			if (start_x + x >= 0 && start_y + y >= 0
				&& start_x + x < WIN_WIDTH && start_y + y < WIN_HEIGHT)
				mlx_put_pixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static uint32_t	get_colors(t_game *game, int col, int row, int len)
{
	uint32_t	color;

	if (col < len && (row == (int)game->player.pos_y
			&& col == (int)game->player.pos_x))
		color = MINIMAP_PLAYER;
	else if (col < len && game->map.grid[row][col] == '1')
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

	allign_right = WIN_WIDTH - (game->map.width * MINIMAP_TILE)
		- MINIMAP_PADDING;
	if (allign_right < MINIMAP_PADDING)
		allign_right = MINIMAP_PADDING;
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		len = (int)ft_strlen(game->map.grid[row]);
		while (col < game->map.width)
		{
			color = get_colors(game, col, row, len);
			minimap(img, allign_right + (col * MINIMAP_TILE),
				MINIMAP_PADDING + (row * MINIMAP_TILE), color);
			col++;
		}
		row++;
	}
	minimap_compass(img, game);
}
