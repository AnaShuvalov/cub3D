/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:42:36 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 15:05:02 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	on_release(mlx_key_data_t key, t_game *game)
{
	if (key.key == MLX_KEY_W)
		game->key.w = false;
	if (key.key == MLX_KEY_A)
		game->key.a = false;
	if (key.key == MLX_KEY_S)
		game->key.s = false;
	if (key.key == MLX_KEY_D)
		game->key.d = false;
	if (key.key == MLX_KEY_LEFT)
		game->key.left = false;
	if (key.key == MLX_KEY_RIGHT)
		game->key.right = false;
}

static void	on_press(mlx_key_data_t key, t_game *game)
{
	if (key.key == MLX_KEY_W)
		game->key.w = true;
	if (key.key == MLX_KEY_A)
		game->key.a = true;
	if (key.key == MLX_KEY_S)
		game->key.s = true;
	if (key.key == MLX_KEY_D)
		game->key.d = true;
	if (key.key == MLX_KEY_LEFT)
		game->key.left = true;
	if (key.key == MLX_KEY_RIGHT)
		game->key.right = true;
}

void	key_reaction(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(game);
	if (keydata.action == MLX_PRESS)
		on_press(keydata, game);
	if (keydata.action == MLX_RELEASE)
		on_release(keydata, game);
}
