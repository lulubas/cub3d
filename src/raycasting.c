/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/06 18:11:09 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_rays(int x, int width, t_scene *scene)
{
	double camX;
	
	//Rays vectors from the Player through the plane
	camX = 2 * x / (double)width - 1;
	scene->rayDirX = scene->playerDirX + scene->planeX * camX;
	scene->rayDirY = scene->playerDirY + scene->planeY * camX;

	//Ray's initial grid position
	scene->mapX = scene->playerPosX;
	scene->mapY = scene->playerPosY;
}
//Distances between each grid lines
void	get_deltadist(t_scene *scene)
{
	if (scene->rayDirX == 0)
		scene->deltaDistX = 1e42;
	else
		scene->deltaDistX = fabs(1 / scene->rayDirX);
	if (scene->rayDirY == 0)
		scene->deltaDistY = 1e42;
	else
		scene->deltaDistY = fabs(1 / scene->rayDirY);
}

//Side distances from Player to next grid lines
void	get_sidedist(t_scene *scene)
{
	if (scene->rayDirX < 0)
		{
			scene->stepX = -1;
			scene->sideDistX = (scene->playerPosX - scene->mapX) * scene->deltaDistX;
		}
		else
		{
			scene->stepX =   1;
			scene->sideDistX = (scene->mapX + 1 - scene->playerPosX) * scene->deltaDistX;
		}
	if (scene->rayDirY < 0)
		{
			scene->stepY = -1;
			scene->sideDistY = (scene->playerPosY - scene->mapY) * scene->deltaDistY;
		}
		else
		{
			scene->stepY = 1;
			scene->sideDistY = (scene->mapY + 1.0 - scene->playerPosY) * scene->deltaDistY;
		}
}

void	get_walldist(int side, t_scene *scene)
{
	if (side == EAST || side == WEST)
		scene->perpWallDist = scene->sideDistX - scene->deltaDistX;
	else
		scene->perpWallDist = scene->sideDistY - scene->deltaDistY;
}

//DDA aLgorythm to find which wall is hit first
t_walldir	perform_dda(t_scene *scene, t_tile **map)
{
	int hit;
	t_walldir side;

	hit = 0;
	while (hit == 0)
	{
		if (scene->sideDistX < scene->sideDistY)
		{
			scene->sideDistX += scene->deltaDistX;
			scene->mapX += scene->stepX;
			if (scene->stepX > 0)
				side = WEST;
			else
				side = EAST;
		}
		else
		{
			scene->sideDistY += scene->deltaDistY;
			scene->mapY += scene->stepY;
			if (scene->stepY > 0)
				side = NORTH;
			else
				side = SOUTH;
		}
		if (map[scene->mapY][scene->mapX] == WALL)
			hit =1;
	}
	return(side);
}

// void draw_line(int x, int start, int end, int color, t_data *data)
// {
// 	int	y;

// 	y = 0;
// 	while (y <= start)
// 		mlx_pixel_put(data->mlx, data->win, x, y++, data->C_color);
// 	while (y <= end)
//         mlx_pixel_put(data->mlx, data->win, x, y++, color);
// 	while (y <= SCREEN_HEIGHT)
// 		mlx_pixel_put(data->mlx, data->win, x, y++, data->F_color);
// }

// //Calculate how the wall length to print on the verical line
// void	draw_wall(int x, int side, t_data *data)
// {
	// int lineHeight;
	// int drawStart;
	
	// lineHeight = (int)((double)SCREEN_HEIGHT / data->scene->perpWallDist);
	// drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	// if(drawStart < 0)
	// 	drawStart = 0;
	// int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	// if(drawEnd >= SCREEN_HEIGHT)
	// 	drawEnd = SCREEN_HEIGHT - 1;
// 	if (side == 1)
// 		draw_line(x, drawStart, drawEnd, COLOR_BLUE, data);
// 	else
// 		draw_line(x, drawStart, drawEnd, COLOR_WHITE, data);
// 	x++;
// }

void draw_line(int x, int start, int end, int color, t_data *data)
{

}

//Calculate how the wall length to print on the verical line
void	draw_wall(int x, int side, t_scene *scene)
{
	int lineHeight;
	int drawStart;
	
	lineHeight = (int)((double)SCREEN_HEIGHT / scene->perpWallDist);
	drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
	
	double	wallX;
	int		texX;
	int		texY;
	double	texStep;
	double 	texPos;
	int		y;

	y = drawStart;
	if (side == EAST || side == WEST)
		wallX = scene->playerDirX + (scene->rayDirX * scene->perpWallDist);
	else
		wallX = scene->playerDirY + (scene->rayDirY * scene->perpWallDist);
	wallX -= (int)wallX;

	texX = (int)(wallX * (double)TEXTURE_WIDTH);
	if ((side == EAST || side == WEST) && scene->rayDirX > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	else if ((side == NORTH || side == SOUTH) && scene->rayDirY > 0)
		texX = TEXTURE_WIDTH - texX - 1;

	texStep = 1.0 * TEXTURE_HEIGHT/SCREEN_HEIGHT;
	texPos = (drawStart - (SCREEN_HEIGHT / 2) + (lineHeight / 2)) * texStep;

	while (y < drawEnd)
	{
		texY = (int)texPos & (TEXTURE_HEIGHT - 1);
		texPos += step;

	}

}



int	raycast_and_render(t_data *data)
{	
	int 		x;
	t_walldir	side;

	x = 0;
	mlx_clear_window(data->mlx, data->win);
	process_input(data);
	while (x < SCREEN_WIDTH)
	{
		get_rays(x, SCREEN_WIDTH, data->scene);
		get_deltadist(data->scene);
		get_sidedist(data->scene);
		side = perform_dda(data->scene, data->map);
		get_walldist(side, data->scene);
		draw_wall(x, side, data->scene);
		x++;
	}
	return (0);
}
