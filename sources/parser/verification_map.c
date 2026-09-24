/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/24 14:56:12 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_space_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (ERROR);
		i++;
	}
	return (OK);
}

int	empty_lines_in_map_linked_list(t_list *map)
{
	t_list	*prev;
	t_list	*to_check;

	prev = NULL;
	while (map)
	{
		if (is_space_only(map->content) == OK)
		{
			to_check = map;
			while (to_check)
			{
				if (is_space_only(to_check->content) == ERROR)
					return (error_message("Empty lines inside map.\n"), ERROR);
				to_check = to_check->next;
			}
			if (prev)
				prev->next = NULL;
			ft_lstclear(&map, free);
			return (OK);
		}
		prev = map;
		map = map->next;
	}
	return (OK);
}

int	create_map_linked_list(char *line, t_list **map)
{
	t_list	*new_node;
	char	*copied;

	copied = ft_strdup(line);
	if (copied == NULL)
		return (ERROR);
	new_node = ft_lstnew(copied);
	if (new_node == NULL)
	{
		free(copied);
		return (ERROR);
	}
	ft_lstadd_back(map, new_node);
	return (OK);
}

int	check_for_map(char *line)
{
	int	i;

	i = 0;
	if (line == NULL || line[0] == '\0')
		return (ERROR);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != ' '
			&& line[i] != '\n')
			return (ERROR);
		i++;
	}
	return (OK);
}

void	check_and_convert_map_into_grid(t_list *map, t_game *game)
{
	if (empty_lines_in_map_linked_list(map) == ERROR)
	{
		ft_lstclear(&map, free);
		free_game(game);
		exit(1);
	}
	if (list_to_grid(map, game) == ERROR)
	{
		ft_lstclear(&map, free);
		free_game(game);
		ft_error("Failed to build map grid\n");
	}
}
