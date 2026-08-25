/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:20:17 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/25 19:06:29 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parser(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		ft_error("Input only one .cub map path.\n");
	verification(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Check permissions for the map file.\n");
	read_map(fd, game);
	close(fd);
	return (0);
}
