/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:11:09 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/09 12:49:04 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map.floor_color = -1;
	game->map.ceiling_color = -1;
	game->light.light_falloff = 0.2;
	game->light.min_brightness = 0.1;
	game->light.max_brightness = 1.0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (parser(argc, argv, &game) != 0)
		return (1);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3D", false);
	if (game.mlx == NULL)
	{
		free_game(&game);
		return (1);
	}
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_key_hook(game.mlx, key_reaction, &game);
	if (start_game(&game) != 0)
	{
		close_game(&game);
		return (1);
	}
	close_game(&game);
	return (0);
}
