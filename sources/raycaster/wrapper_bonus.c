/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:58:47 by olmatske          #+#    #+#             */
/*   Updated: 2026/10/22 16:48:11 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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
