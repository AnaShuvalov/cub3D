/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 09:59:16 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/24 14:59:19 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_enclosed_by_walls(t_game *game, int y, int x, int len)
{
	int	above_row_len;
	int	below_row_len;

	if (y == 0 || y == game->map.height - 1 || x == 0 || x == len - 1)
		return (ERROR);
	above_row_len = ft_strlen(game->map.grid[y - 1]);
	below_row_len = ft_strlen(game->map.grid[y + 1]);
	if (x >= above_row_len || game->map.grid[y - 1][x] == ' ')
		return (ERROR);
	if (x >= below_row_len || game->map.grid[y + 1][x] == ' ')
		return (ERROR);
	if (game->map.grid[y][x + 1] == ' ' || game->map.grid[y][x - 1] == ' ')
		return (ERROR);
	return (OK);
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
				if (is_enclosed_by_walls(game, y, x, len) == ERROR)
					return (ERROR);
			}
			x++;
		}
		y++;
	}
	return (OK);
}

int	list_to_grid(t_list *map, t_game *game)
{
	int		i;
	int		len;
	t_list	*tmp;

	if (map == NULL)
		return (error_message("Missing map data in provided file.\n"), ERROR);
	game->map.height = ft_lstsize(map);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (game->map.grid == NULL)
		return (error_message("Memory allocation failed for map.\n"), ERROR);
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
	return (OK);
}
