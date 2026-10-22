/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:58:47 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/22 15:07:58 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (x < 0 || y < 0 || map_y >= game->map.height || map_x >= game->map.width)
		return (1);
	if (!game->map.grid[map_y])
		return (1);
	if (map_x >= (int)ft_strlen(game->map.grid[map_y]))
		return (1);
	if (game->map.grid[map_y][map_x] != '0')
		return (1);
	return (0);
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	walk_forward_backward(t_game *game)
{
	double	move_x;
	double	move_y;
	double	speed;

	move_x = 0;
	move_y = 0;
	speed = MOVEMENT_SPEED * game->mlx->delta_time;
	if (game->key.w)
	{
		move_x = game->player.dir_x * speed;
		move_y = game->player.dir_y * speed;
	}
	if (game->key.s)
	{
		move_x -= game->player.dir_x * speed;
		move_y -= game->player.dir_y * speed;
	}
	if (!is_wall(game, game->player.pos_x + move_x,
			game->player.pos_y + move_y))
	{
		game->player.pos_x += move_x;
		game->player.pos_y += move_y;
	}
}

void	strafe_left_right(t_game *game)
{
	double	move_x;
	double	move_y;
	double	speed;

	move_x = 0;
	move_y = 0;
	speed = MOVEMENT_SPEED * game->mlx->delta_time;
	if (game->key.a)
	{
		move_x = -game->player.plane_x * speed;
		move_y = -game->player.plane_y * speed;
	}
	if (game->key.d)
	{
		move_x = game->player.plane_x * speed;
		move_y = game->player.plane_y * speed;
	}
	if (!is_wall(game, game->player.pos_x + move_x, game->player.pos_y))
		game->player.pos_x += move_x;
	if (!is_wall(game, game->player.pos_x, game->player.pos_y + move_y))
		game->player.pos_y += move_y;
}

void	direction_handler(t_game *game)
{
	double	rotation_speed;

	rotation_speed = ROTATION_SPEED * game->mlx->delta_time;
	if (game->key.right)
		rotate_player(&game->player, rotation_speed);
	if (game->key.left)
		rotate_player(&game->player, -rotation_speed);
	if (game->key.w || game->key.s)
		walk_forward_backward(game);
	if (game->key.a || game->key.d)
		strafe_left_right(game);
}

// void	print_fps_terminal(void)
// {
// 	static double	last_time = 0;
// 	static int		frame_count = 0;
// 	struct timeval	time;
// 	double			current_time;

// 	gettimeofday(&time, NULL);
// 	current_time = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
// 	frame_count++;
// 	if (current_time - last_time >= 1000.0)
// 	{
// 		printf("FPS: %d\n", frame_count);
// 		frame_count = 0;
// 		last_time = current_time;
// 	}
// }
