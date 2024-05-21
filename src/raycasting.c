/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/06 12:25:03 by lbastien         ###   ########.fr       */
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

	//Ray's initial grid position
	data->mapX = data->player_x;
	data->mapY = data->player_y;
}
//Distances between each grid lines
void	get_deltadist(double rayDirX, double rayDirY, t_data *data)
{
	if (rayDirX == 0)
		data->deltaDistX = 1e42;
	else
		data->deltaDistX = fabs(1 / rayDirX);
	if (rayDirY == 0)
		data->deltaDistY = 1e42;
	else
		data->deltaDistY = fabs(1 / rayDirY);
}

//Side distances from Player to next grid lines
void	get_sidedist(double rayDirX, double rayDirY, t_data *data)
{
	if (rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->playerPosX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX =   1;
			data->sideDistX = (data->mapX + 1 - data->playerPosX) * data->deltaDistX;
		}
	if (rayDirY < 0)
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

double get_walldist(int side, t_data *data)
{
	double perpWallDist;
	
	if (side == 1)
		perpWallDist = data->sideDistX - data->deltaDistX;
	else
		perpWallDist = data->sideDistY - data->deltaDistY;
	return (perpWallDist);
}

//DDA aLgorythm to find which wall is hit first
int	perform_dda(t_data *data)
{
	int hit;
	int side;

	hit = 0;
	side = 0;
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
	return(side);
}

void draw_line(void *mlx, void *win, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
        mlx_pixel_put(mlx, win, x, y++, color);
}

//Calculate how the wall length to print on the verical line
void	draw_wall(int x, int side, double perpWallDist, t_data *data)
{
	int lineHeight = (int)(data->height / perpWallDist);
	int drawStart = -lineHeight / 2 + data->height / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + data->height / 2;
	if(drawEnd >= data->height)
		drawEnd = data->height - 1;
	if (side == 1)
		draw_line(data->mlx, data->win, x, drawStart, drawEnd, COLOR_GREEN);
	else
		draw_line(data->mlx, data->win, x, drawStart, drawEnd, COLOR_RED);
	x++;
}


int	raycast_and_render(t_data *data)
{	
	int 	x;
	double	rayDirX;
	double	rayDirY;
	int		side;
	double	perpWallDist;

	x = 0;
	mlx_clear_window(data->mlx, data->win);
	process_input(data);
	while (x < data->width)
	{
		get_rays(x, &rayDirX, &rayDirY, data);
		get_deltadist(rayDirX, rayDirY, data);
		get_sidedist(rayDirX, rayDirY, data);
		side = perform_dda(data);
		perpWallDist = get_walldist(side, data);
		draw_wall(x, side, perpWallDist, data);
		x++;
	}
	return (0);
}
