/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/01 17:05:19 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void verLine(void *mlx, void *win, int x, int start, int end, int color) {
    for (int y = start; y <= end; y++) {
        mlx_pixel_put(mlx, win, x, y, color);
    }
}

void	raycast_and_render(t_data *data)
{	
	int 	x;
	int		hit = 0;
	int		side = 0;
	double	perpWallDist = 0;

	x = 0;
	while (x < data->width)
	{
		//Rays vectors from the Player through the plane
		data->camX = 2 * x / data->height - 1;
		data->rayDirX = data->dirX + data->planeX * data->camX;
		data->rayDirY = data->dirY + data->planeY * data->camX;

		//Player's initial position (middle of the grid case)
		data->posX = data->player_x + 0.5;
		data->posY = data->player_y + 0.5;

		//Ray's initial grid position
		data->mapX = data->player_x;
		data->mapY = data->player_y;

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
			data->stepX =   1;
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

		//DDA aLgorythm to find which wall is hit first
		while (hit == 0)
		{
			if (data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				side = 1;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				side = 2;
			}
			if (data->map[data->mapY][data->mapX] == WALL)
				hit =1;
		}
		//Extract the (perpendicular) wall distance from the DDA
		if (side == 1)
			perpWallDist = data->sideDistX - data->deltaDistX;
		else
			perpWallDist = data->sideDistY - data->deltaDistY;
		
		//Calculate how the wall length to print on the verical line
		int lineHeight = (int)(data->height / perpWallDist);
		int drawStart = -lineHeight / 2 + data->height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + data->height / 2;
		if(drawEnd >= data->height)
			drawEnd = data->height - 1;
			
		verLine(data->mlx, data->win, x, drawStart, drawEnd, COLOR_GREEN);
		x++;
	}
}