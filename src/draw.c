/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:21:33 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:44 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int get_texX(t_scene *scene)
{
	int 	texX;
	double	wallX;
	
	if (scene->side == EAST || scene->side == WEST)
		wallX = scene->playerPosY + (scene->rayDirY * scene->perpWallDist);
	else
		wallX = scene->playerPosX + (scene->rayDirX * scene->perpWallDist);
	wallX -= (int)wallX;
	texX = (int)(wallX * (double)TEXTURE_WIDTH);
	if ((scene->side == EAST || scene->side == WEST) && scene->rayDirX > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	else if ((scene->side == NORTH || scene->side == SOUTH) && scene->rayDirY > 0)
		texX = TEXTURE_WIDTH - texX - 1;
	return (texX);
}

void	draw_wall(int x, int *y, t_image *buffer, t_scene *scene, t_data *data)
{
	int		texX;
	int		texY;
	int 	color;
	int		pixel;
    t_image texture;
	
	texX = get_texX(scene);

	scene->texStep = 1.0 * TEXTURE_HEIGHT / scene->lineHeight;
	scene->texPos = (scene->drawStart - SCREEN_HEIGHT / 2 + scene->lineHeight / 2) * scene->texStep;
	while (*y < scene->drawEnd)
	{
		texY = (int)scene->texPos % TEXTURE_HEIGHT;
		scene->texPos += scene->texStep;
		pixel = (*y * buffer->line_bytes) + (x * 4);
        texture = load_texture(scene, data);
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
void	draw_slice(int x, t_image *buffer, t_scene *scene, t_data *data)
{
	int		y;

	y = 0;	
	draw_ceiling(x, &y, data->C_color, buffer, scene);
	draw_wall(x, &y, buffer, scene, data);
	draw_floor(x, &y, data->F_color, buffer);
}