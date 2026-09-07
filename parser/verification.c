/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:58 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/28 17:59:10 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	verify_color(t_game *game, const char *line)
{
	char	**rgb;
	char	*color;

	if (ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0)
		return (error_message("Invalid Color line naming.\n"), -1);
	color = (char *) line + 1;
	while (*color == ' ' || *color == '\t')
		color++;
	rgb = ft_split(color, ',');
	if (rgb == NULL || rgb[0] == NULL || rgb[1] == NULL
		|| rgb[2] == NULL || rgb[3] != NULL)
	{
		free_array(rgb);
		return (error_message("Invalid Color wording.\n"), -1);
	}
	if (is_rgb(game, line, rgb) == -1)
	{
		free_array(rgb);
		return (-1);
	}
	free_array(rgb);
	return (0);
}

int	check_path_validity(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

char	*verify_path(t_game *game, const char *line)
{
	char	**splitted;

	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WO ", 3) != 0 && ft_strncmp(line, "EO ", 3) != 0)
		return (error_message("Invalid Texture line naming.\n"), -1);
	splitted = ft_split(line, ' ');
	if (splitted == NULL || splitted[0] == NULL || splitted[1] == NULL
		|| splitted[2] != NULL || check_path_validity(splitted[1]) == -1)
	{
		free_array(splitted);
		return (error_message("Invalid Texture wording or path "
				"does not exist.\n"), -1);
	}
	if (splitted[0][1] == 'N' && game->map.north_texture_path == NULL)
		game->map.north_texture_path = splitted[1];
	else if (splitted[0][1] == 'S' && game->map.south_texture_path == NULL)
		game->map.south_texture_path = splitted[1];
	else if (splitted[0][1] == 'W' && game->map.west_texture_path == NULL)
		game->map.west_texture_path = splitted[1];
	else if (splitted[0][1] == 'E' && game->map.east_texture_path == NULL)
		game->map.east_texture_path = splitted[1];
	else
		return (error_message("Dupplicated Texture path line.\n"), -1);
	free_array(splitted);
	return (0);
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
	if (game->map.grid == NULL)
		ft_error("Missing map data.\n");
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
