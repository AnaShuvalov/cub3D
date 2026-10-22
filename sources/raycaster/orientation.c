/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:58:47 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/22 11:32:00 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	rotate_player(t_player *player, double angle)
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

static void	move_player(t_game *game, double speed)
{
	if (game->key.w)
	{
		game->player.pos_x += game->player.dir_x * speed;
		game->player.pos_y += game->player.dir_y * speed;
	}
	if (game->key.s)
	{
		game->player.pos_x -= game->player.dir_x * speed;
		game->player.pos_y -= game->player.dir_y * speed;
	}
	if (game->key.a)
	{
		game->player.pos_x -= game->player.plane_x * speed;
		game->player.pos_y -= game->player.plane_y * speed;
	}
	if (game->key.d)
	{
		game->player.pos_x += game->player.plane_x * speed;
		game->player.pos_y += game->player.plane_y * speed;
	}
}

void	direction_handler(t_game *game)
{
	double	rotation_speed;
	double	speed;

	rotation_speed = ROTATION_SPEED * game->mlx->delta_time;
	speed = MOVEMENT_SPEED * game->mlx->delta_time;
	if (game->key.right)
		rotate_player(&game->player, rotation_speed);
	if (game->key.left)
		rotate_player(&game->player, -rotation_speed);
	else
		move_player(game, speed);
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
