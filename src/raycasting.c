/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/25 18:16:13 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y)
	{
		while(x < data->map_x)
		{
			if (data->map[y][x] == NORTH || data->map[y][x] == SOUTH || \
				data->map[y][x] == EAST || data->map[y][x] == WEST)
			{
				data->posX = x;
				data->posY = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	raycast_and_render(t_data *data)
{
	get_player_position(data);
}