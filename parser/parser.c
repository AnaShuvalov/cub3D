/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:20:17 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/07 14:15:36 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	populate_game(t_game *game, char *line)
{
	char	*path;
	int		color;
	bool	inside_map;

	inside_map = check_for_map(line);
	if (is_space_only(line) == 0 && inside_map == 0)
		return (0);
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
	{
		if (verify_path(game, line) == -1)
			return (-1);
	}
	if (line[0] == 'F' || line[0] == 'C')
	{
		if (verify_color(game, line) == -1)
			return (-1);
	}
	else if (inside_map == 1)
	{
		if (verify_map(game, line) == -1)
			return (-1);
	}
	else
		return (error_message("Extra information in the .cub file.\n"), -1);
	return (0);
}

static void	read_map(int fd, t_game *game)
{
	char	buffer[1];
	char	*line;
	int		len;

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
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (populate_game(game, line) == -1)
		{
			free(line);
			ft_error("The map path is unreadable\n");
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
