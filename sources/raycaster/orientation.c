/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:21:16 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/25 22:21:25 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "math.h"

// static int	is_wall(t_game *game, double x, double y)
// {
// 	int	map_x;
// 	int	map_y;

// 	map_x = (int)x;
// 	map_y = (int)y;
// 	if (map_y < 0 || map_y >= game->map.height || map_x < 0 || map_x >= game->map.width)
// 		return (1);
// 	if (game->map.grid[map_y][map_x] > '0')
// 		return (1);
// 	return (0);
// }

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	direction_handler(t_game *game)
{
	if (game->key.right)
		rotate_player(&game->player, ROTATION_SPEED);
	if (game->key.left)
		rotate_player(&game->player, -ROTATION_SPEED);
	
}