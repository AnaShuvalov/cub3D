/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcolors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:58:47 by olmatske          #+#    #+#             */
/*   Updated: 2026/09/26 21:58:58 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#define COLOR_NORTH	0x00008BFF
#define COLOR_SOUTH	0xB8860BFF
#define COLOR_WEST	0x006400FF
#define COLOR_EAST	0x8B0000FF


uint32_t	get_wall_color(t_ray *ray)
{
	uint32_t	color;

	if (ray->side == 0) // the ray hit the vertical axis which is left or right side of the wall
	{
		if (ray->step_x > 0)
			color = COLOR_WEST;
		else
			color = COLOR_EAST;
	}
	else
	{
		if (ray->step_y > 0)
			color = COLOR_NORTH;
		else
			color = COLOR_SOUTH;
	}
	return (color);
}
