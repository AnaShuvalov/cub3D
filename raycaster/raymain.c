/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*   tske          #+#    #+#             */
/*   Updated: 2026/09/09 15:03:31 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "raycast.h"
#include "../MLX42/MLX42.h"

int main()
{
    printf("test\n");
    int *mlx;
    int *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, 800, 600, "Cub3D");
    if (!win)
        return (1);
    mlx_loop(mlx);

    return (0);
}

