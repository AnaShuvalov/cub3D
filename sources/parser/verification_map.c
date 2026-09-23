/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:23:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/23 17:01:48 by anshuval         ###   ########.fr       */
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
			return (NO);
		i++;
	}
	return (YES);
}

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
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_and_convert_map_into_grid(t_list *map, t_game *game)
{
	if (empty_lines_in_map_linked_list(map) == -1)
	{
		ft_lstclear(&map, free);
		free_game(game);
		exit(1);
	}
	if (list_to_grid(map, game) == -1)
	{
		ft_lstclear(&map, free);
		free_game(game);
		ft_error("Failed to build map grid\n");
	}
}
