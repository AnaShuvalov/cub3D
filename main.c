/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshuval <anshuval@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 19:11:09 by anshuval          #+#    #+#             */
/*   Updated: 2026/08/25 19:14:23 by anshuval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (parser(argc, argv, &game) != 0)
		return (1);
	return (0);
}