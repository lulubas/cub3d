/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/22 16:11:18 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Side distances from Player to next grid lines
void	parse_sidedist(t_scene *scene)
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

//Get Rays vectors from the Player through the plane
//and initial position of rays
void init_rays(int x, int width, t_scene *scene)
{
	double camX;
		camX = 2 * x / (double)width - 1;
	scene->rayDirX = scene->playerDirX + scene->planeX * camX;
	scene->rayDirY = scene->playerDirY + scene->planeY * camX;
	scene->mapX = (int)scene->playerPosX;
	scene->mapY = (int)scene->playerPosY;
	if (scene->rayDirX == 0)
		scene->deltaDistX = 1e42;
	else
		scene->deltaDistX = fabs(1 / scene->rayDirX);
	if (scene->rayDirY == 0)
		scene->deltaDistY = 1e42;
	else
		scene->deltaDistY = fabs(1 / scene->rayDirY);
	parse_sidedist(scene);
}

//DDA aLgorythm to find which wall is hit first
void	perform_dda(t_scene *scene, t_tile **map)
{
	t_walldir hit_side;

	while (1)
	{
		if (scene->sideDistX < scene->sideDistY)
		{
			scene->sideDistX += scene->deltaDistX;
			scene->mapX += scene->stepX;
			if (scene->stepX > 0)
				hit_side = WEST;
			else
				hit_side = EAST;
		}
		else
		{
			scene->sideDistY += scene->deltaDistY;
			scene->mapY += scene->stepY;
			if (scene->stepY > 0)
				hit_side = NORTH;
			else
				hit_side = SOUTH;
		}
		if (map[scene->mapY][scene->mapX] == WALL)
			break ;
	}
	scene->side = hit_side;
}

//Calculate perpendicalr distance of the wall to the plane
//and the lineheight zith the the start and end of the wall slice
void	split_slice(t_scene *scene)
{	
	if (scene->side == EAST || scene->side == WEST)
		scene->perpWallDist = scene->sideDistX - scene->deltaDistX;
	else
		scene->perpWallDist = scene->sideDistY - scene->deltaDistY;
	scene->lineHeight = (int)((double)SCREEN_HEIGHT / scene->perpWallDist);
	scene->drawStart = -scene->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(scene->drawStart < 0)
		scene->drawStart = 0;
	scene->drawEnd = scene->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(scene->drawEnd >= SCREEN_HEIGHT)
		scene->drawEnd = SCREEN_HEIGHT - 1;
}