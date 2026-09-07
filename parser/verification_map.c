/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/28 18:06:20 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	verify_map(t_game *game, char *line)
{
	// char	**splitted;

	// if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
	// 	&& ft_strncmp(line, "WO ", 3) != 0 && ft_strncmp(line, "EO ", 3) != 0)
	// 	return (error_message("Invalid Texture line naming.\n"), -1);
	// splitted = ft_split(line, ' ');
	// if (splitted == NULL || splitted[0] == NULL || splitted[1] == NULL
	// 	|| splitted[2] != NULL || check_path_validity(splitted[1]) == -1)
	// {
	// 	free_array(splitted);
	// 	return (error_message("Invalid Texture wording or path "
	// 			"does not exist.\n"), -1);
	// }
	// if (splitted[0][1] == 'N' && game->map.north_texture_path == NULL)
	// 	game->map.north_texture_path = splitted[1];
	// else if (splitted[0][1] == 'S' && game->map.south_texture_path == NULL)
	// 	game->map.south_texture_path = splitted[1];
	// else if (splitted[0][1] == 'W' && game->map.west_texture_path == NULL)
	// 	game->map.west_texture_path = splitted[1];
	// else if (splitted[0][1] == 'E' && game->map.east_texture_path == NULL)
	// 	game->map.east_texture_path = splitted[1];
	// else
	// 	return (error_message("Dupplicated Texture path line.\n"), -1);
	// free_array(splitted);
	// return (0);
}
