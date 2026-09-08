/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/08 12:59:15 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	validate_grid(t_game *game)
{
	
}

void	set_player(t_game *game)
{
	
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
