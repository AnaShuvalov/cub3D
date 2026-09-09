/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:49:34 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/08 17:47:12 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	verify_metadata(t_game *game)
{
	if (game->map.north_texture_path == NULL
		|| game->map.south_texture_path == NULL
		|| game->map.west_texture_path == NULL
		|| game->map.east_texture_path == NULL)
	{
		free_game(game);
		ft_error("Missing wall textures.\n");
	}
	if (game->map.floor_color == -1 || game->map.ceiling_color == -1)
	{
		free_game(game);
		ft_error("Missing floor or ceiling colors.\n");
	}
	if (game->map.grid == NULL)
	{
		free_game(game);
		ft_error("Missing map data.\n");
	}
}
