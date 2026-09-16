/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:11:09 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/08 17:40:56 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map.floor_color = -1;
	game->map.ceiling_color = -1;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (parser(argc, argv, &game) != 0)
		return (1);
	printf("North: %s\n", game.map.north_texture_path);
	printf("South: %s\n", game.map.south_texture_path);
	printf("West: %s\n", game.map.west_texture_path);
	printf("East: %s\n", game.map.east_texture_path);
	printf("Floor: %d %d %d\n", (game.map.floor_color / 65536) % 256, (game.map.floor_color / 256) % 256, game.map.floor_color % 256);
	printf("Ceiling: %d %d %d\n", (game.map.ceiling_color / 65536) % 256, (game.map.ceiling_color / 256) % 256, game.map.ceiling_color % 256);
	if (game.map.grid)
	{
		int i = 0;
		printf("Grid\n");
		while (game.map.grid[i])
		{
			printf("Row %d: %s\n", i, game.map.grid[i]);
			i++;
		}
		printf("Player info\n");
		printf("Position X: %.2f, Y: %.2f\n", game.player.pos_x, game.player.pos_y);
		printf("Direction X: %.2f, Y: %.2f\n", game.player.dir_x, game.player.dir_y);
		printf("Plane X: %.2f, Y: %.2f\n", game.player.plane_x, game.player.plane_y);
	}
	if (start_game(game))
		return (1);
	free_game(&game);
	return (0);
}
