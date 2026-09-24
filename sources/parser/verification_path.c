/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:58 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/24 14:57:08 by anshuval         ###   ########.fr       */
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
		return (error_message("Duplicate Texture path line.\n"), ERROR);
	if ((splitted[0][0] == 'N' && game->map.north_texture_path == NULL)
		|| (splitted[0][0] == 'S' && game->map.south_texture_path == NULL)
		|| (splitted[0][0] == 'W' && game->map.west_texture_path == NULL)
		|| (splitted[0][0] == 'E' && game->map.east_texture_path == NULL))
		return (error_message("Memory allocation for Texture path "
				"failed.\n"), ERROR);
	return (OK);
}

static int	check_path_validity(char *path)
{
	int		fd;
	char	buffer[1];

	if (path == NULL || path[0] == '\0')
		return (ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	if (read(fd, buffer, 1) < 0)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (OK);
}

int	verify_path(t_game *game, const char *line)
{
	char	**splitted;

	if (ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0 && ft_strncmp(line, "EA ", 3) != 0)
		return (error_message("Invalid Texture line naming.\n"), ERROR);
	splitted = ft_split(line, ' ');
	if (splitted == NULL || splitted[0] == NULL || splitted[1] == NULL
		|| splitted[2] != NULL)
	{
		free_array(splitted);
		return (error_message("Invalid Texture wording.\n"), ERROR);
	}
	if (check_path_validity(splitted[1]) == ERROR)
	{
		free_array(splitted);
		return (error_message("Invalid texture path.\n"), ERROR);
	}
	if (path_allocation(splitted, game) == ERROR)
	{
		free_array(splitted);
		return (ERROR);
	}
	free_array(splitted);
	return (OK);
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
	if (ft_strncmp(&filename[len - 5], "/.cub", 5) == 0)
		ft_error("A hidden cub file is being passed instead of the "
			".cub file.\n");
}
