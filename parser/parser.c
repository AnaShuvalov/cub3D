/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:20:17 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/26 18:34:39 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	populate_game(t_game *game, char *line)
{
	char	*path;

	if (is_space_only(line) == 0)
		return (0);
	path = verify_path(line);
	if (path == NULL)
		return (-1);
	if (line[0] == 'N')
		game->map.north_texture_path = path;
	else if (line[0] == 'S')
		game->map.south_texture_path = path;
	else if (line[0] == 'W')
		game->map.west_texture_path = path;
	else if (line[0] == 'E')
		game->map.east_texture_path = path;
	else if (line[0] == 'F')
		game->map.floor_color = path;
	else if (line[0] == 'C')
		game->map.ceiling_color = path;
	else if (check_for_map(line) == -1)
		return (-1);
	else
		return (-1);
	return (0);
}

static void	read_map(int fd, t_game *game)
{
	char	buffer[1];
	char	*line;

	if (read(fd, buffer, 0) < 0)
	{
		close(fd);
		ft_error("The map path is unreadable\n");
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (populate_game(game, line) == -1)
		{
			free(line);
			exit(1);
		}
		free(line);
	}
}

int	parser(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		ft_error("Input only one .cub map path.\n");
	verification(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Check permissions for the map file.\n");
	read_map(fd, game);
	close(fd);
	verify_metadata(game);
	return (0);
}
