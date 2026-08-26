/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:58 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/26 18:24:43 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*verify_path(const char *line)
{
	char **splitted;

	splitted = ft_split(line, ' ');
	if (splitted[0][1] == 'N' || splitted[0][1] == 'S' || splitted[0][1] == 'W'
		|| splitted[0][1] == 'E')
	return (-1);
}

void	verify_metadata(t_game *game)
{
	if (game->map.north_texture_path == NULL
			|| game->map.south_texture_path == NULL
			|| game->map.west_texture_path == NULL
			|| game->map.east_texture_path == NULL)
		ft_error("Missing wall textures.\n");
	if (game->map.floor_color == -1 || game->map.ceiling_color == -1)
		ft_error("Missing floor or ceiling colors.\n");
}

void	verification(char *filename)
{
	int	len;

	if (filename == NULL || filename[0] == '\0')
		ft_error("Input only one .cub map path.\n");
	len = ft_strlen(filename);
	if (len < 5)
		ft_error("Invalid map path.\n");
	if (ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
		ft_error("Map file must have a .cub extension.\n");
}
