/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:02:54 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/26 18:30:27 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"

int		parser(int argc, char **argv, t_game *game);
void	verification(char *filename);
void	ft_error(char *s);
void	verify_metadata(t_game *game);
char	*verify_path(const char *line);
int		is_space_only(char *line);

#endif