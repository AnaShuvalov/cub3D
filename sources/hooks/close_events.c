/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:42:32 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 17:27:15 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
