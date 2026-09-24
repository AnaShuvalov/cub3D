/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:39:36 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/24 14:57:30 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	direction_horisontal(t_game *game, char direction)
{
	if (direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

static void	direction_vertical(t_game *game, char direction)
{
	if (direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static int	set_player_pos_and_dir(t_game *game, int x, int y, int count)
{
	if (game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
				|| game->map.grid[y][x] == 'W' || game->map.grid[y][x] == 'E')
	{
		game->player.pos_x = x + 0.5;
		game->player.pos_y = y + 0.5;
		if (game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S')
			direction_vertical(game, game->map.grid[y][x]);
		else if (game->map.grid[y][x] == 'W' || game->map.grid[y][x] == 'E')
			direction_horisontal(game, game->map.grid[y][x]);
		game->map.grid[y][x] = '0';
		count++;
	}
	return (count);
}

int	set_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			count = set_player_pos_and_dir(game, x, y, count);
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ERROR);
	return (OK);
}
