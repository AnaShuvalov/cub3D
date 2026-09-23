/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:27:12 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 19:04:13 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define TILE 10
#define PADDING 20

#define COLOR_CEILING		0x55e4ffFF
#define COLOR_WALLS			0x895544FF
#define COLOR_FLOOR			0x56db32FF
#define COLOR_PLAYER 		0xcb137fFF
#define COLOR_SPACE 		0xf7f7f7FF

static void	minimap(mlx_image_t *img, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE)
	{
		x = 0;
		while (x < TILE)
		{
			if (start_x + x >= 0 && start_y + y >= 0
				&& start_x + x < WIN_WIDTH && start_y + y < WIN_HEIGHT)
				mlx_put_pixel(img, x, y, color);
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
		color = COLOR_PLAYER;
	else if (col < len && game->map.grid[row][col] == '1')
		color = COLOR_WALLS;
	else if (col < len && game->map.grid[row][col] == '0')
		color = COLOR_FLOOR;
	else
		color = COLOR_SPACE;
	return (color);
}

static void	draw_map(mlx_image_t *img, t_game *game)
{
	int			row;
	int			col;
	int			len;
	int			allign_right;
	uint32_t	color;

	allign_right = WIN_WIDTH - (game->map.width * TILE);
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		len = (int)ft_strlen(game->map.grid[row]);
		while (col < game->map.width)
		{
			color = get_colors(game, col, row, len);
			minimap(img, allign_right + (col * TILE), row * TILE, color);
			col++;
		}
		row++;
	}
}

static void	game_loop(void *param)
{
	t_game	*game;

	game = param;
	render_frame(game);
	draw_map(game->framebuffer, game);
}

int	start_game(t_game *game)
{
	game->framebuffer = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->framebuffer)
		return (1);
	if (mlx_image_to_window(game->mlx, game->framebuffer, 0, 0) == -1)
		return (1);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
