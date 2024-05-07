/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/07 15:58:05 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene *init_scene(void)
{
	t_scene	*new_scene;
	
	new_scene = malloc(sizeof(t_scene));
	new_scene->playerPosX = -99;
	new_scene->playerPosY = -99;
	new_scene->playerDirX = -99;
	new_scene->playerDirY = -99;
	new_scene->rayDirX = -99;
	new_scene->rayDirY = -99;
	new_scene->planeX = -99;
	new_scene->planeY = -99;
	new_scene->sideDistX = -99;
	new_scene->sideDistY = -99;
	new_scene->deltaDistX = -99;
	new_scene->deltaDistY = -99;
	new_scene->mapX = -99;
	new_scene->mapY = -99;
	new_scene->stepX = -99;
	new_scene->stepY = -99;
	new_scene->perpWallDist = -99;
	new_scene->no_img = NULL;
	new_scene->so_img = NULL;
	new_scene->ea_img = NULL;
	new_scene->we_img = NULL;
	return(new_scene);
}

t_data *init_data_struct(void)
{
	t_data *new_data;

	new_data = malloc(sizeof(t_data));
	new_data->filepath = NULL;
	new_data->no_texture = NULL;
	new_data->so_texture = NULL;
	new_data->ea_texture = NULL;
	new_data->we_texture = NULL;
	new_data->F_color = -1;
	new_data->C_color = -1;
	new_data->map_x = 0;
	new_data->map_y = 0;
	new_data->lst = NULL;
	new_data->map = NULL;
	new_data->scene = init_scene();
	new_data->buffer = NULL;
	new_data->mlx = NULL;
	new_data->win = NULL;
	new_data->img_buffer = NULL;
	new_data->map_x = -99;
	new_data->map_y = -99;
	new_data->up_pressed = false;
	new_data->down_pressed = false;
	new_data->left_pressed = false;
	new_data->right_pressed = false;
	return(new_data);
}