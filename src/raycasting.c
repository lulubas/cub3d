/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/16 16:16:34 by lbastien         ###   ########.fr       */
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
	scene->mapX = (int)scene->playerPosX;
	scene->mapY = (int)scene->playerPosY;
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
	(void)map;
	while (hit == 0)
	{
		//print_scene(scene);
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
		{
			hit = 1;
		}
	}
	return(side);
}

//Calculate the y of the start and end of the wall
void	get_lineheight(t_scene *scene)
{
	int lineHeight;
	
	lineHeight = (int)((double)SCREEN_HEIGHT / scene->perpWallDist);
	scene->drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(scene->drawStart < 0)
		scene->drawStart = 0;
	scene->drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if(scene->drawEnd >= SCREEN_HEIGHT)
		scene->drawEnd = SCREEN_HEIGHT - 1;
}

//Calculate how the wall length to print on the verical line
void	draw_wall(int x, int side, t_scene *scene, t_data *data)
{
	int		y;
	int 	color;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		text_pixel_bits;
	int		text_line_bytes;
	int		text_endian;


	char *buffer = mlx_get_data_addr(data->img_buffer, &pixel_bits, &line_bytes, &endian);
	char *text_data = mlx_get_data_addr(scene->no_img, &text_pixel_bits, &text_line_bytes, &text_endian);
	y = scene->drawStart;
	double	wallX;
	int		texX;
	int		texY;
	double	texStep;
	double 	texPos;

	int lineHeight = (int)((double)SCREEN_HEIGHT / scene->perpWallDist);

	//Get the relative position (between 0 & 1) where the ray hists the wall
	if (side == EAST || side == WEST)
		wallX = scene->playerDirX + (scene->rayDirX * scene->perpWallDist);
	else
		wallX = scene->playerDirY + (scene->rayDirY * scene->perpWallDist);
	wallX -= (int)wallX;

	//Account for mirroring
	texX = (int)(wallX * (double)TEXTURE_WIDTH);
	if ((side == EAST || side == WEST) && scene->rayDirX > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	else if ((side == NORTH || side == SOUTH) && scene->rayDirY > 0)
		texX = TEXTURE_WIDTH - texX - 1;

	texX = texX % TEXTURE_WIDTH;
	if (texX < 0) texX += TEXTURE_WIDTH; // Handle negative values correctly

	texStep = 1.0 * TEXTURE_HEIGHT/SCREEN_HEIGHT;
	texPos = (scene->drawStart - (SCREEN_HEIGHT / 2) + (lineHeight / 2)) * texStep;

	while (y < scene->drawEnd)
	{
		texY = (int)texPos & (TEXTURE_HEIGHT - 1);
		texPos += texStep;

		if (texX < 0 || texX >= TEXTURE_WIDTH || texY < 0 || texY >= TEXTURE_HEIGHT) 
		{
			printf("Invalid texX or texY: texX=%d, texY=%d\n", texX, texY);
			continue;
    	}

		int pixel_index = (texY * text_line_bytes) + (texX * (text_pixel_bits / 8));
		
		if (pixel_index < 0 || pixel_index >= text_line_bytes * TEXTURE_HEIGHT)
		{
        	printf("Pixel index out of bounds: %d\n", pixel_index);
        	continue;
    	}

        color = *(unsigned int *)(text_data + pixel_index);

		printf("texX=%d, texY=%d, color=%u\n", texX, texY, color);

		int pixel = (y * line_bytes) + (x * 4);

		if (pixel < 0 || pixel >= line_bytes * SCREEN_HEIGHT)
		{
        	printf("Screen pixel index out of bounds: %d\n", pixel);
        	continue;
    	}

		if (endian == 1)        // Most significant (Alpha) byte first
		{
			buffer[pixel + 0] = (color >> 24) & 0xFF;
			buffer[pixel + 1] = (color >> 16) & 0xFF;
			buffer[pixel + 2] = (color >> 8) & 0xFF;
			buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (endian == 0)   // Least significant (Blue) byte first
		{
			buffer[pixel + 0] = (color) & 0xFF;
			buffer[pixel + 1] = (color >> 8) & 0xFF;
			buffer[pixel + 2] = (color >> 16) & 0xFF;
			buffer[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

int	raycast_and_render(t_data *data)
{	
	int 		x;
	t_walldir	side;
	data->img_buffer = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);

	x = 0;
	process_input(data);
	while (x < SCREEN_WIDTH)
	{
		get_rays(x, SCREEN_WIDTH, data->scene);
		get_deltadist(data->scene);
		get_sidedist(data->scene);
		side = perform_dda(data->scene, data->map);
		get_walldist(side, data->scene);
		get_lineheight(data->scene);
		draw_wall(x, side, data->scene, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_buffer, 0, 0);
	mlx_destroy_image(data->mlx, data->img_buffer);
	return (0);
}
