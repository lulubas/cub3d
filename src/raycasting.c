/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 13:15:35 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Get Rays vectors from the Player through the plane
//and initial position of rays
void get_rays(int x, int width, t_scene *scene)
{
	double camX;
		camX = 2 * x / (double)width - 1;
	scene->rayDirX = scene->playerDirX + scene->planeX * camX;
	scene->rayDirY = scene->playerDirY + scene->planeY * camX;
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

//Calculate perpendicalr distance of the wall to the plane
//and the lineheight zith the the start and end of the wall slice
void	parse_slice(t_walldir side, t_scene *scene)
{	
	if (side == EAST || side == WEST)
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

int get_texX(t_walldir side, t_scene *scene)
{
	int 	texX;
	double	wallX;
	
	if (side == EAST || side == WEST)
		wallX = scene->playerPosY + (scene->rayDirY * scene->perpWallDist);
	else
		wallX = scene->playerPosX + (scene->rayDirX * scene->perpWallDist);
	wallX -= (int)wallX;
	texX = (int)(wallX * (double)TEXTURE_WIDTH);
	if ((side == EAST || side == WEST) && scene->rayDirX > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	else if ((side == NORTH || side == SOUTH) && scene->rayDirY > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	// texX = texX % TEXTURE_WIDTH;
	// if (texX < 0) 
	// 	texX += TEXTURE_WIDTH;
	return (texX);
}

int		get_color(int texX, int texY, t_image *texture)
{
	int 	pixel_index;
	int		color;
	
	pixel_index = (texY * texture->line_bytes) + (texX * (texture->pixel_bits / 8));
    color = *(unsigned int *)(texture->image + pixel_index);
	return (color);
}

void	put_pixel(int pixel, int color, t_image *buffer)
{
	if (buffer->endian == 1)        // Most significant (Alpha) byte first
	{
		buffer->image[pixel + 0] = (color >> 24) & 0xFF;
		buffer->image[pixel + 1] = (color >> 16) & 0xFF;
		buffer->image[pixel + 2] = (color >> 8) & 0xFF;
		buffer->image[pixel + 3] = (color) & 0xFF;
	}
	else if (buffer->endian == 0)   // Least significant (Blue) byte first
	{
		buffer->image[pixel + 0] = (color) & 0xFF;
		buffer->image[pixel + 1] = (color >> 8) & 0xFF;
		buffer->image[pixel + 2] = (color >> 16) & 0xFF;
		buffer->image[pixel + 3] = (color >> 24);
	}
}

t_image load_texture(t_walldir side, t_scene *scene, t_data *data)
{
	t_image texture;

	texture.image = NULL;
    texture.pixel_bits = 0;
    texture.line_bytes = 0;
    texture.endian = 0;
	if (side == NORTH)
		texture.image = mlx_get_data_addr(scene->no_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (side == SOUTH)
		texture.image = mlx_get_data_addr(scene->so_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (side == EAST)
		texture.image = mlx_get_data_addr(scene->ea_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (side == WEST)
		texture.image = mlx_get_data_addr(scene->we_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	if (texture.image == NULL)
		ft_error(data, "Failed to load texture", 1);
	return (texture);
}

void	draw_ceiling(int x, int *y, int color, t_image *buffer, t_scene *scene)
{
	int pixel;

	while (*y < scene->drawStart)
	{
		pixel = (*y * buffer->line_bytes) + (x * 4);
		put_pixel(pixel, color, buffer);
		(*y)++;
	}
}

void	draw_wall(int x, int *y, t_walldir side, t_image *buffer, t_scene *scene, t_data *data)
{
	int		texX;
	int		texY;
	int 	color;
	int		pixel;
	t_image texture;
	
	texture = load_texture(side, scene, data);
	texX = get_texX(side, scene);

	scene->texStep = 1.0 * TEXTURE_HEIGHT / scene->lineHeight;
	scene->texPos = (scene->drawStart - SCREEN_HEIGHT / 2 + scene->lineHeight / 2) * scene->texStep;
	while (*y < scene->drawEnd)
	{
		texY = (int)scene->texPos % TEXTURE_HEIGHT;
		scene->texPos += scene->texStep;
		pixel = (*y * buffer->line_bytes) + (x * 4);
		color = get_color(texX, texY, &texture);
		put_pixel(pixel, color, buffer);
		(*y)++;
	}
}

void	draw_floor(int x, int *y, int color, t_image *buffer)
{
	int pixel;

	while (*y < SCREEN_HEIGHT)
	{
		pixel = (*y * buffer->line_bytes) + (x * 4);
		put_pixel(pixel, color, buffer);
		(*y)++;
	}
}

//Calculate how the wall length to print on the verical line
void	draw_slice(int x, t_walldir side, t_image *buffer, t_scene *scene, t_data *data)
{
	int		y;

	y = 0;	
	draw_ceiling(x, &y, data->C_color, buffer, scene);
	draw_wall(x, &y, side, buffer, scene, data);
	draw_floor(x, &y, data->F_color, buffer);
}

int	raycast_and_render(t_data *data)
{	
	int 		x;
	t_walldir	side;
	char		*img_buffer;
	t_image		buffer;

	x = 0;
	process_input(data);
	img_buffer = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	buffer.image = mlx_get_data_addr(img_buffer, &buffer.pixel_bits, &buffer.line_bytes, &buffer.endian);
	while (x < SCREEN_WIDTH)
	{
		get_rays(x, SCREEN_WIDTH, data->scene);
		get_deltadist(data->scene);
		get_sidedist(data->scene);
		side = perform_dda(data->scene, data->map);
		parse_slice(side, data->scene);
		draw_slice(x, side, &buffer, data->scene, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img_buffer, 0, 0);
	mlx_destroy_image(data->mlx, img_buffer);
	return (0);
}
