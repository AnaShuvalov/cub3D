/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:20:17 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 17:07:14 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	verify_metadata(t_game *game)
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

static int	populate_game(t_game *game, char *line, t_list **map)
{
	char	*start;

	if (is_space_only(line) == YES && *map == NULL)
		return (0);
	start = line;
	while (*start == ' ')
		start++;
	if (*map != NULL && (start[0] == 'N' || start[0] == 'S' || start[0] == 'W'
			|| start[0] == 'E' || start[0] == 'F' || start[0] == 'C'))
		return (error_message("Map should be last info in file.\n"), -1);
	if (start[0] == 'N' || start[0] == 'S'
		|| start[0] == 'W' || start[0] == 'E')
		return (verify_path(game, start));
	else if (start[0] == 'F' || start[0] == 'C')
		return (verify_color(game, start));
	else if (check_for_map(line) == 1
		|| (is_space_only(line) == YES && *map != NULL))
		return (create_map_linked_list(line, map));
	else
		return (error_message("Extra information in the .cub file.\n"), -1);
	return (0);
}

static void	convert_map_to_list(int fd, t_game *game)
{
	char	*line;
	t_list	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		replace_with_spaces(line);
		if (populate_game(game, line, &map) == -1)
		{
			free(line);
			ft_lstclear(&map, free);
			free_game(game);
			exit(1);
		}
		free(line);
	}
	check_and_convert_map_into_grid(map, game);
}

static void	read_map(int fd, t_game *game)
{
	convert_map_to_list(fd, game);
	if (set_player(game) == -1)
	{
		free_game(game);
		ft_error("Only one player spawn point per map is allowed.\n");
	}
	if (validate_grid(game) == -1)
	{
		free_game(game);
		ft_error("Invalid map. Not enclosed by walls.\n");
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
