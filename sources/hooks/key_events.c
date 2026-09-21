/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:42:36 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/21 17:01:59 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	new_field_of_view(t_game *game)
{
	
}

static int	new_position(t_game *game, double new_x, double new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map.width
			|| new_y >= game->map.height)
		return (-1);
	if (game->map.grid[new_y][new_x] == '1')
		return (-1);
	game->map.grid[game->player.pos_y][game->player.pos_x] = '0';
	game->player.pos_x = new_x;
	game->player.pos_y = new_y;
	return (0);
}

static int	new_direction_of_view(int key, t_game *game)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_x = game->player.dir_x;
	new_dir_y = game->player.dir_y;
	if (key == KEY_LEFT)
	{
		new_dir_x--;
		new_dir_y--;
	}
	if (key == KEY_RIGHT)
	{
		new_dir_x++;
		new_dir_y++;
	}
	game->player.dir_x = new_dir_x;
	game->player.dir_y = new_dir_y;
	new_field_of_view(game);
}

int	key_reaction(int key, t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x;
	new_pos_y = game->player.pos_y;
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W)
		new_pos_x--;
	if (key == KEY_S)
		new_pos_x++;
	if (key == KEY_A)
		new_pos_y--;
	if (key == KEY_D)
		new_pos_y++;
	if (new_pos_x != game->player.pos_x || new_pos_y != game->player.pos_y)
	{
		if (new_position(game, new_pos_x, new_pos_y) == 0)
			new_field_of_view(game);
	}
	new_direction_of_view(key, game);
	return (0);
}
