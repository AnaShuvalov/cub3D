/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:20:17 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/09 16:15:47 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	populate_game(t_game *game, char *line, t_list **map)
{
	if (is_space_only(line) == 0)
	{
		if (*map != NULL)
			return (error_message("Empty line inside the map.\n"), -1);
		return (0);
	}
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E'
		|| line[0] == 'F' || line[0] == 'C')
	{
		if (*map != NULL)
			return (error_message("No viable data is allowed after map in "
					".cub file.\n"), -1);
	}
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
	{
		if (verify_path(game, line) == -1)
			return (-1);
	}
	else if (line[0] == 'F' || line[0] == 'C')
	{
		if (verify_color(game, line) == -1)
			return (-1);
	}
	else if (check_for_map(line) == 1)
	{
		if (create_map_linked_list(line, map) == -1)
			return (-1);
	}
	else
		return (error_message("Extra information in the .cub file.\n"), -1);
	return (0);
}

static void	convert_map_to_list(int fd, t_game *game)
{
	int		len;
	char	*line;
	t_list	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (populate_game(game, line, &map) == -1)
		{
			free(line);
			ft_lstclear(&map, free);
			free_game(game);
			exit(1);
		}
		free(line);
	}
	if (list_to_grid(map, game) == -1)
	{
		ft_lstclear(&map, free);
		free_game(game);
		ft_error("Failed to build map grid\n");
	}
}

static void	read_map(int fd, t_game *game)
{
	char	buffer[1];

	if (read(fd, buffer, 0) < 0)
	{
		close(fd);
		ft_error("The map path is unreadable\n");
	}
	convert_map_to_list(fd, game);
	if (set_player(game) == -1)
	{
		free_game(game);
		ft_error("Only one player spawn point per map is allowed.\n");
	}
	if (validate_grid(game) == -1)
	{
		free_game(game);
		ft_error("Invalid map\n");
	}
}

int	parser(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		ft_error("Input only one .cub map path.\n");
	verify_map_pathname(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Check permissions for the map file.\n");
	read_map(fd, game);
	close(fd);
	verify_metadata(game);
	return (0);
}
