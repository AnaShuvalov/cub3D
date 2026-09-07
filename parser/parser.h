/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:54 by anshuval          #+#    #+#             */
/*   Updated: 2026/09/07 16:26:25 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"

int		parser(int argc, char **argv, t_game *game);
void	verification(char *filename);
void	ft_error(char *s);
void	error_message(char *s);
void	verify_metadata(t_game *game);
int		verify_path(t_game *game, const char *line);
int		verify_color(t_game *game, const char *line);
int		create_map_linked_list(t_game *game, char *line, t_list **map);
int		is_space_only(char *line);
void	free_array(char **array);
bool	check_for_map(char *line);
int		check_path_validity(char *path);
int		is_rgb(t_game *game, const char *line, char **rgb);
int		path_allocation(char **splitted, t_game *game);
int		list_to_grid(t_list **map, t_game *game);
int		validate_grid(t_list **map, t_game *game);

#endif