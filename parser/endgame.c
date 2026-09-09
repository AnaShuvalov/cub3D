/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:57:13 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/09 16:03:34 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map.north_texture_path)
		free(game->map.north_texture_path);
	if (game->map.south_texture_path)
		free(game->map.south_texture_path);
	if (game->map.west_texture_path)
		free(game->map.west_texture_path);
	if (game->map.east_texture_path)
		free(game->map.east_texture_path);
	if (game->map.grid)
		free_array(game->map.grid);
}
