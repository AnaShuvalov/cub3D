/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:27:12 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/07 13:25:10 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_loop(void *param)
{
	t_game	*game;

	game = param;
	render_frame(game);
	draw_map(game->framebuffer, game);
}

int	start_game(t_game *game)
{
	if (load_textures(&game->map) != 0)
	{
		printf("ERROR: Failed to load textures\n");
		mlx_close_window(game->mlx);
		return (1);
	}
	game->framebuffer = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->framebuffer)
		return (1);
	game->background = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->background)
		return (1);
	if (mlx_image_to_window(game->mlx, game->background, 0, 0) == -1)
		return (1);
	if (mlx_image_to_window(game->mlx, game->framebuffer, 0, 0) == -1)
		return (1);
	draw_floor_and_ceiling(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
