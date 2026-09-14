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

void	myppixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	mlx_put_pixel(img, x, y, color);
}

void	sqare(mlx_image_t *img, int start_x, int start_y, unint32_t color)
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

int	main()
{
	printf("test\n");
	mlx_t	*mlx;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
	if (!mlx)
		return (1);
	mlx_loop(mlx);

	return (0);
}

