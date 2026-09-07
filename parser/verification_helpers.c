/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:22:35 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/28 17:54:16 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_rgb(char *rgb)
{
	int	i;

	if (rgb == NULL || rgb[0] == '\0')
		return (error_message("No or invalid color in the map.\n"), -1);
	i = 0;
	while (rgb[i])
	{
		while (rgb[i] == ' ' || rgb[i] == '\t')
			i++;
		if (rgb[i] == '\0')
			return (error_message("No or invalid color in the map.\n"), -1);
		while (ft_isdigit(rgb[i]))
			i++;
		if (rgb[i] != ' ' && rgb[i] != '\t' && rgb[i] != '\0')
			return (error_message("No or invalid color in the map.\n"), -1);
		i++;
	}
	return (0);
}

int	is_rgb(t_game *game, char *line, char **rgb)
{
	int	i;
	int	r;
	int	g;
	int	b;

	if (rgb == NULL || rgb[0] == '\0' || rgb[1] == '\0' || rgb[2] == '\0')
		return (error_message("No or invalid color in the map.\n"), -1);
	i = 0;
	while (rgb[i])
	{
		if (check_rgb(rgb[i]) == -1)
			return (-1);
		i++;
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (error_message("Invalid color in the map.\n"), -1);
	if (line[0] == 'F' && game->map.floor_color == NULL)
		game->map.floor_color = ((r << 16) | (g << 8) | b);
	else if (line[0] == 'C' && game->map.ceiling_color == NULL)
		game->map.ceiling_color = ((r << 16) | (g << 8) | b);
	else
		return (error_message("Dupplicated Color line.\n"), -1);
	return (0);
}
