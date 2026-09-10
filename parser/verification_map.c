/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/10 16:44:53 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	empty_lines_in_map_linked_list(t_list *map)
{
	t_list	*prev;
	t_list	*to_check;

	prev = NULL;
	while (map)
	{
		if (is_space_only(map->content) == YES)
		{
			to_check = map;
			while (to_check)
			{
				if (is_space_only(to_check->content) == NO)
					return (error_message("Empty lines inside map.\n"), -1);
				to_check = to_check->next;
			}
			if (prev)
				prev->next = NULL;
			ft_lstclear(&map, free);
			return (0);
		}
		prev = map;
		map = map->next;
	}
	return (0);
}

static int	is_enclosed_by_walls(t_game *game, int y, int x, int len)
{
	int	above_row_len;
	int	below_row_len;

	if (y == 0 || y == game->map.height - 1 || x == 0 || x == len -1)
		return (-1);
	above_row_len = ft_strlen(game->map.grid[y - 1]);
	below_row_len = ft_strlen(game->map.grid[y + 1]);
	if (x >= above_row_len || game->map.grid[y - 1][x] == ' ')
		return (-1);
	if (x >= below_row_len || game->map.grid[y + 1][x] == ' ')
		return (-1);
	if (game->map.grid[y][x + 1] == ' ' || game->map.grid[y][x - 1] == ' ')
		return (-1);
	return (0);
}

int	validate_grid(t_game *game)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		len = ft_strlen(game->map.grid[y]);
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == '0')
			{
				if (is_enclosed_by_walls(game, y, x, len) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	list_to_grid(t_list *map, t_game *game)
{
	int		i;
	int		len;
	t_list	*tmp;

	if (map == NULL)
		return (error_message("Missing map data in provided file.\n"), -1);
	game->map.height = ft_lstsize(map);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (game->map.grid == NULL)
		return (error_message("Memory allocation failed for map grid.\n"), -1);
	game->map.width = 0;
	i = 0;
	while (map)
	{
		game->map.grid[i] = map->content;
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		tmp = map;
		map = map->next;
		free(tmp);
		i++;
	}
	game->map.grid[i] = NULL;
	return (0);
}

int	create_map_linked_list(char *line, t_list **map)
{
	t_list	*new_node;
	char	*copied;

	copied = ft_strdup(line);
	if (copied == NULL)
		return (-1);
	new_node = ft_lstnew(copied);
	if (new_node == NULL)
	{
		free(copied);
		return (-1);
	}
	ft_lstadd_back(map, new_node);
	return (0);
}

bool	check_for_map(char *line)
{
	int	i;

	i = 0;
	if (line == NULL || line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != ' '
			&& line[i] != '\n' && line[i] != '\t' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}
