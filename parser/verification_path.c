/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:58 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/09 15:59:00 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	path_allocation(char **splitted, t_game *game)
{
	if (splitted[0][0] == 'N' && game->map.north_texture_path == NULL)
		game->map.north_texture_path = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'S' && game->map.south_texture_path == NULL)
		game->map.south_texture_path = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'W' && game->map.west_texture_path == NULL)
		game->map.west_texture_path = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'E' && game->map.east_texture_path == NULL)
		game->map.east_texture_path = ft_strdup(splitted[1]);
	else
		return (error_message("Dupplicated Texture path line.\n"), -1);
	if ((splitted[0][0] == 'N' && game->map.north_texture_path == NULL)
		|| (splitted[0][0] == 'S' && game->map.south_texture_path == NULL)
		|| (splitted[0][0] == 'W' && game->map.west_texture_path == NULL)
		|| (splitted[0][0] == 'E' && game->map.east_texture_path == NULL))
		return (error_message("Memory allocation for Texture path "
				"failed.\n"), -1);
	return (0);
}

static int	check_path_validity(char *path)
{
	int	fd;
	int	len;

	if (path == NULL || path[0] == '\0')
		return (-1);
	len = ft_strlen(path);
	if (len < 5)
		return (-1);
	if (ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	verify_path(t_game *game, const char *line)
{
	char	**splitted;

	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0)
		return (error_message("Invalid Texture line naming.\n"), -1);
	splitted = ft_split(line, ' ');
	if (splitted == NULL || splitted[0] == NULL || splitted[1] == NULL
		|| splitted[2] != NULL || check_path_validity(splitted[1]) == -1)
	{
		free_array(splitted);
		return (error_message("Invalid Texture wording or path "
				"does not exist.\n"), -1);
	}
	if (path_allocation(splitted, game) == -1)
	{
		free_array(splitted);
		return (-1);
	}
	free_array(splitted);
	return (0);
}

void	verify_map_pathname(char *filename)
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
