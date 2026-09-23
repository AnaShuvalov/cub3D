/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:27:12 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 15:10:32 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define TILE 64

#define COLOR_CEILING		0x55e4ffFF
#define COLOR_WALLS			0x895544FF
#define COLOR_FLOOR			0x56db32FF
#define COLOR_PLAYER 		0xcb137fFF
#define COLOR_SPACE 		0xf7f7f7FF

static void	myppixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	mlx_put_pixel(img, x, y, color);
}

static void	draw_square(mlx_image_t *img, int start_x, int start_y, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE)
	{
		x = 0;
		while (x < TILE)
		{
			myppixel(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_map(mlx_image_t *img, t_game *game)
{
	int			row;
	int			col;
	uint32_t	color;

	row = 0;
	while (game->map.grid[row])
	{
		col = 0;
		while (game->map.grid[row][col])
		{
			if (row == (int)game->player.pos_y
				&& col == (int)game->player.pos_x)
				color = COLOR_PLAYER;
			else if (game->map.grid[row][col] == '1')
				color = COLOR_WALLS;
			else if (game->map.grid[row][col] == '0')
				color = COLOR_FLOOR;
			else
				color = COLOR_SPACE;
			draw_square(img, col * TILE, row * TILE, color);
			col++;
		}
		row++;
	}
}

int	start_game(t_game *game)
{
	game->framebuffer = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->framebuffer)
		return (1);
	if (mlx_image_to_window(game->mlx, game->framebuffer, 0, 0) == -1)
		return (1);
	draw_map(game->framebuffer, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
