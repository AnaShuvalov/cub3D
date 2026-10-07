/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:11:09 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/05 15:43:02 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map.north_texture)
		free(game->map.north_texture);
	if (game->map.south_texture)
		free(game->map.south_texture);
	if (game->map.west_texture)
		free(game->map.west_texture);
	if (game->map.east_texture)
		free(game->map.east_texture);
	if (game->map.grid)
		free_array(game->map.grid);
}

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

	// printf("North: %s\n", game.map.north_texture_path);
	// printf("South: %s\n", game.map.south_texture_path);
	// printf("West: %s\n", game.map.west_texture_path);
	// printf("East: %s\n", game.map.east_texture_path);
	// printf("Floor: %d %d %d\n", (game.map.floor_color / 65536) % 256, (game.map.floor_color / 256) % 256, game.map.floor_color % 256);
	// printf("Ceiling: %d %d %d\n", (game.map.ceiling_color / 65536) % 256, (game.map.ceiling_color / 256) % 256, game.map.ceiling_color % 256);
	// if (game.map.grid)
	// {
	// 	int i = 0;
	// 	printf("Grid\n");
	// 	while (game.map.grid[i])
	// 	{
	// 		printf("Row %d: %s\n", i, game.map.grid[i]);
	// 		i++;
	// 	}
	// 	printf("Player info\n");
	// 	printf("Position X: %.2f, Y: %.2f\n", game.player.pos_x, game.player.pos_y);
	// 	printf("Direction X: %.2f, Y: %.2f\n", game.player.dir_x, game.player.dir_y);
	// 	printf("Plane X: %.2f, Y: %.2f\n", game.player.plane_x, game.player.plane_y);
	// }