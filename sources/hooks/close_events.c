/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:42:32 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/09 12:54:37 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_game *game)
{
	if (game->map.north_texture)
		mlx_delete_texture(game->map.north_texture);
	if (game->map.south_texture)
		mlx_delete_texture(game->map.south_texture);
	if (game->map.west_texture)
		mlx_delete_texture(game->map.west_texture);
	if (game->map.east_texture)
		mlx_delete_texture(game->map.east_texture);
}

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
	free_textures(game);
	if (game->mlx)
	{
		if (game->framebuffer)
			mlx_delete_image(game->mlx, game->framebuffer);
		if (game->background)
			mlx_delete_image(game->mlx, game->background);
	}
	if (game->map.grid)
		free_array(game->map.grid);
	ft_bzero(&game->map, sizeof(t_map));
}

void	exit_on_error(t_game *game, char *s)
{
	if (s)
		error_message(s);
	close_game(game);
}

void	close_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_game(game);
	exit(0);
}

void	close_hook(void *param)
{
	t_game	*game;

	game = param;
	close_game(game);
}
