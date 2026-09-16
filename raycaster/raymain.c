/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*   tske          #+#    #+#             */
/*   Updated: 2026/09/09 15:03:31 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	myppixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	mlx_put_pixel(img, x, y, color);
}

static void	draw_sqare(mlx_image_t *img, int start_x, int start_y, uint32_t color)
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

static static void	draw_map(mlx_image_t *img, char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row][col] != '\0')
	{
		col = 0;
		{
			if (map[row][col] == '1')
				color = COLOR_WALLS;
			else if (map[row][col] == 'N' || map[row][col] == 'S' 
					|| map[row][col] == 'E' || map[row][col] == 'W' ||);
					color = COLOR_PLAYER;
			else
				color = COLOR_PLAYER;

			draw_square(img, col * TILE, row * TILE, color);
			col++;
		}	
		row++;
	}
}

int	start_game(t_game game)
{
	printf("start\n");
	mlx_t	*mlx;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
	if (!mlx)
		return (1);

	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
		return (1);

	draw_map(img, game->map);

	mlx_loop(mlx);

	printf("finish\n");
	return (0);
}

