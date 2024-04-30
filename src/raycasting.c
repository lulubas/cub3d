/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 19:00:15 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_and_render(t_data *data)
{	
	int x;

	x = 0;
	while (x < data->res_length)
	{
		//Rays vectors from the Player through the plane
		data->camX = 2 * x / data->res_length - 1;
		data->rayDirX = data->dirX + data->planeX * data->camX;
		data->rayDirY = data->dirY + data->planeY * data->camX;

		//Ray's initial grid position
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;

		//Side distances from Player to next grid lines
		if (data->rayDirX == 0)
			data->deltaDistX = 1e42;
		else
			data->deltaDistX = fabs(1 / data->rayDirX);
		if (data->rayDirY == 0)
			data->deltaDistY = 1e42;
		else
			data->deltaDistY = fabs(1 / data->rayDirY);

		//Determine ray steps direction in the grid
		if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = -1;
			data->sideDistX = (data->mapX + 1 - data->posX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
	}

}