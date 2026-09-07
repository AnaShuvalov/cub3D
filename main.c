/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:11:09 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/07 14:53:44 by anshuval         ###   ########.fr       */
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

	return (0);
}
