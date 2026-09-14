/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:22:35 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/14 13:39:55 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	assign_colors(t_game *game, char **rgb, const char *line)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (error_message("Invalid color in the map.\n"), -1);
	if (line[0] == 'F' && game->map.floor_color == -1)
		game->map.floor_color = ((r << 16) | (g << 8) | b);
	else if (line[0] == 'C' && game->map.ceiling_color == -1)
		game->map.ceiling_color = ((r << 16) | (g << 8) | b);
	else
		return (error_message("Duplicate Color line.\n"), -1);
	return (0);
}

static int	check_rgb(char *rgb)
{
	int	i;

	if (rgb == NULL || rgb[0] == '\0')
		return (error_message("No or invalid color in the map.\n"), -1);
	i = 0;
	while (rgb[i] == ' ' || rgb[i] == '\t')
		i++;
	if (!ft_isdigit(rgb[i]))
		return (error_message("No or invalid color in the map.\n"), -1);
	while (ft_isdigit(rgb[i]))
		i++;
	while (rgb[i] == ' ' || rgb[i] == '\t')
		i++;
	if (rgb[i] != '\0')
		return (error_message("No or invalid color in the map.\n"), -1);
	return (0);
}

static int	is_rgb(t_game *game, const char *line, char **rgb)
{
	int	i;

	if (rgb == NULL || rgb[0][0] == '\0' || rgb[1][0] == '\0'
			|| rgb[2][0] == '\0')
		return (error_message("No or invalid color in the map.\n"), -1);
	i = 0;
	while (rgb[i])
	{
		if (check_rgb(rgb[i]) == -1)
			return (-1);
		i++;
	}
	if (assign_colors(game, rgb, line) == -1)
		return (-1);
	return (0);
}

static int	count_commas(char *color)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (color[i])
	{
		if (color[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

int	verify_color(t_game *game, const char *line)
{
	char	**rgb;
	char	*color;

	if (ft_strncmp(line, "F ", 2) != 0 && ft_strncmp(line, "C ", 2) != 0)
		return (error_message("Invalid Color line naming.\n"), -1);
	color = (char *) line + 1;
	if (count_commas(color) != 2)
		return (error_message("RGB in the .cub file must be separated "
				"by exactly two commas.\n"), -1);
	while (*color == ' ' || *color == '\t')
		color++;
	rgb = ft_split(color, ',');
	if (rgb == NULL || rgb[0] == NULL || rgb[1] == NULL
		|| rgb[2] == NULL || rgb[3] != NULL)
	{
		free_array(rgb);
		return (error_message("Invalid Color wording.\n"), -1);
	}
	if (is_rgb(game, line, rgb) == -1)
	{
		free_array(rgb);
		return (-1);
	}
	free_array(rgb);
	return (0);
}
