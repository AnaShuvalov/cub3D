/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:43:41 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/27 19:40:28 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	minimap_compass(mlx_image_t *img, t_game *game, int minimap)
{
	int	dot_x;
	int	dot_y;
	int	x;
	int	y;

	dot_x = (int)(minimap + ((game->player.pos_x + game->player.dir_x)
				* MINIMAP_TILE)) - 1;
	dot_y = (int)(PADDING + ((game->player.pos_y + game->player.dir_y)
				* MINIMAP_TILE)) - 1;
	y = 0;
	while (y < MINIMAP_DOT_SIZE)
	{
		x = 0;
		while (x < MINIMAP_DOT_SIZE)
		{
			mlx_put_pixel(img, dot_x + x, dot_y + y, MINIMAP_COMPASS);
			x++;
		}
		y++;
	}
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

static void	get_player(mlx_image_t *img, t_game *game, int allignment)
{
	int	player_x;
	int	player_y;
	int	x;
	int	y;

	player_x = (int)(allignment + (game->player.pos_x * MINIMAP_TILE))
			- (MINIMAP_PLAYER_SIZE / 2);
	player_y = (int)(PADDING + (game->player.pos_y * MINIMAP_TILE))
			- (MINIMAP_PLAYER_SIZE / 2);
	y = 0;
	while (y < MINIMAP_PLAYER_SIZE)
	{
		x = 0;
		while (x < MINIMAP_PLAYER_SIZE)
		{
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

	allign_right = WIN_WIDTH - (game->map.width * MINIMAP_TILE) - PADDING;
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
			minimap(img, allign_right + (col * MINIMAP_TILE),
				PADDING + (row * MINIMAP_TILE), color);
			col++;
		}
		row++;
	}
	get_player(img, game, allign_right);
	minimap_compass(img, game, allign_right);
}
