/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:27:12 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/26 21:40:10 by olmatske         ###   ########.fr       */
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
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
