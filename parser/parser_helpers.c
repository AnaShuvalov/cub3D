/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:27:08 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/28 16:20:23 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_for_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E' || line[i] == ' '
			|| line[i] == '\n' || line[i] == '\t' || line[i] == '\r')
			return (1);
		i++;
	}
	return (0);
}

int	is_space_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r')
			return (-1);
		i++;
	}
	return (0);
}

void	free_array(char **array)
{
	int	i;

	if (array == NULL || array[0] == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
