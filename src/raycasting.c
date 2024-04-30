/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 15:22:33 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_direction_and_plane(t_data *data)
{
	if(data->map[data->map_y][data->map_x] == NORTH)
	{
		data->dirX = 0;
		data->dirY = -1;
		data->planeX = 0.66;
		data->planeY = 0;
	}
	else if(data->map[data->map_y][data->map_x] == SOUTH)
	{
		data->dirX = 0;
		data->dirY = 1;
		data->planeX = 0.66;
		data->planeY = 0;
	}
	else if(data->map[data->map_y][data->map_x] == EAST)
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
	else if(data->map[data->map_y][data->map_x] == SOUTH)
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
}

void	raycast_and_render(t_data *data)
{
	parse_direction_and_plane(data);

}