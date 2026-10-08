/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:22:35 by anshuval          #+#    #+#             */
/*   Updated: 2026/10/07 16:12:09 by anshuval         ###   ########.fr       */
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
		return (error_message("Invalid color in the map.\n"), ERROR);
	if (line[0] == 'F' && game->map.floor_color == ERROR)
		game->map.floor_color = ((r << 24) | (g << 16) | (b << 8) | 0xFF);
	else if (line[0] == 'C' && game->map.ceiling_color == ERROR)
		game->map.ceiling_color = ((r << 24) | (g << 16) | (b << 8) | 0xFF);
	else
		return (error_message("Duplicate Color line.\n"), ERROR);
	return (OK);
}

static int	check_rgb(char *rgb)
{
	int	i;
	int	len;

	if (rgb == NULL || rgb[0] == '\0')
		return (error_message("No or invalid color in the map.\n"), ERROR);
	i = 0;
	len = 0;
	while (rgb[i] == ' ')
		i++;
	if (!ft_isdigit(rgb[i]))
		return (error_message("No or invalid color in the map.\n"), ERROR);
	while (ft_isdigit(rgb[i]))
	{
		i++;
		len++;
	}
	if (len > 3)
		return (error_message("Invalid color in the map.\n"), ERROR);
	while (rgb[i] == ' ')
		i++;
	if (rgb[i] != '\0')
		return (error_message("No or invalid color in the map.\n"), ERROR);
	return (OK);
}

static int	is_rgb(t_game *game, const char *line, char **rgb)
{
	int	i;

	if (rgb == NULL || rgb[0][0] == '\0' || rgb[1][0] == '\0'
			|| rgb[2][0] == '\0')
		return (error_message("No or invalid color in the map.\n"), ERROR);
	i = 0;
	while (rgb[i])
	{
		if (check_rgb(rgb[i]) == ERROR)
			return (ERROR);
		i++;
	}
	if (assign_colors(game, rgb, line) == ERROR)
		return (ERROR);
	return (OK);
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
		return (error_message("Invalid Color line naming.\n"), ERROR);
	color = (char *) line + 1;
	if (count_commas(color) != 2)
		return (error_message("RGB in the .cub file must be separated "
				"by exactly two commas.\n"), ERROR);
	while (*color == ' ')
		color++;
	rgb = ft_split(color, ',');
	if (rgb == NULL || rgb[0] == NULL || rgb[1] == NULL
		|| rgb[2] == NULL || rgb[3] != NULL)
	{
		free_array(rgb);
		return (error_message("Invalid Color wording.\n"), ERROR);
	}
	if (is_rgb(game, line, rgb) == ERROR)
	{
		free_array(rgb);
		return (ERROR);
	}
	free_array(rgb);
	return (OK);
}
