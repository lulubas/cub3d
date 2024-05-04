/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 10:47:12 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_rays(int x, double *rayDirX, double *rayDirY, t_data *data)
{
	double camX;
	
	//Rays vectors from the Player through the plane
	camX = 2 * x / data->height - 1;
	*rayDirX = data->playerDirX + data->planeX * camX;
	*rayDirY = data->playerDirY + data->planeY * camX;

	//Player's initial position (middle of the grid case)
	data->playerPosX = data->player_x + 0.5;
	data->playerPosY = data->player_y + 0.5;

	//Ray's initial grid position
	data->mapX = data->player_x;
	data->mapY = data->player_y;
}

void	get_deltadist(double rayDirX, double rayDirY, t_data *data)
{
	//Side distances from Player to next grid lines
	if (rayDirX == 0)
		data->deltaDistX = 1e42;
	else
		data->deltaDistX = fabs(1 / data->rayDirX);
	if (rayDirY == 0)
		data->deltaDistY = 1e42;
	else
		data->deltaDistY = fabs(1 / data->rayDirY);
}

void	get_sidedist(t_data *data)
{
	if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->playerPosX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX =   1;
			data->sideDistX = (data->mapX + 1 - data->playerPosX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->playerPosY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->playerPosY) * data->deltaDistY;
		}
}

//DDA aLgorythm to find which wall is hit first
double	exec_dda(t_data *data)
{
	int hit;
	int side;
	double perpWallDist;

	hit = 0;
	side = 0;
	perpWallDist = 0;
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
	if (side == 1)
		perpWallDist = data->sideDistX - data->deltaDistX;
	else
		perpWallDist = data->sideDistY - data->deltaDistY;
	return (perpWallDist);
}

void draw_line(void *mlx, void *win, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
        mlx_pixel_put(mlx, win, x, y++, color);
}

//Calculate how the wall length to print on the verical line
int	draw_wall(double perpWallDist, t_data *data)
{
	int lineHeight = (int)(data->height / perpWallDist);
	int drawStart = -lineHeight / 2 + data->height / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + data->height / 2;
	if(drawEnd >= data->height)
		drawEnd = data->height - 1;
	draw_line(data->mlx, data->win, x, drawStart, drawEnd, COLOR_GREEN);
	x++;
}


void	raycast_and_render(t_data *data)
{	
	int 	x;
	double	rayDirX;
	double	rayDirY;
	double 	perpWallDist;

	x = 0;
	while (x < data->width)
	{
		get_rays(x, &rayDirX, &rayDirY, data);
		get_deltadist(rayDirX, rayDirY, data);
		get_sidedist(data);
		perpWallDist = perform_dda(data);
		draw_wall(perpWallDist, data);
		x++;
	}
}
