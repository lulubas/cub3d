/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 20:21:59 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *init_data_struct(void)
{
	t_data *new_data;

	new_data = malloc(sizeof(t_data));
	new_data->filepath = NULL;
	new_data->no_texture = NULL;
	new_data->so_texture = NULL;
	new_data->ea_texture = NULL;
	new_data->we_texture = NULL;
	new_data->F_color = NULL;
	new_data->C_color = NULL;
	new_data->map_x = 0;
	new_data->map_y = 0;
	new_data->lst = NULL;
	new_data->map = NULL;
	new_data->width = 1280;
	new_data->height = 1024;
	new_data->mlx = NULL;
	new_data->win = NULL;
	new_data->playerPosX = -99;
	new_data->playerPosY = -99;
	new_data->mapX = -99;
	new_data->mapY = -99;
	new_data->map_x = -99;
	new_data->map_y = -99;
	new_data->playerDirX = -99;
	new_data->playerDirY = -99;
	new_data->planeX = -99;
	new_data->planeY = -99;
	new_data->sideDistX = -99;
	new_data->sideDistY = -99;
	new_data->deltaDistX = -99;
	new_data->deltaDistY = -99;
	new_data->perpWallDist = -99;
	new_data->stepX = -99;
	new_data->stepY = -99;
	new_data->up_pressed = false;
	new_data->down_pressed = false;
	new_data->left_pressed = false;
	new_data->right_pressed = false;
	return(new_data);
}