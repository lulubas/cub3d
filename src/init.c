/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 18:51:36 by lbastien         ###   ########.fr       */
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
	new_data->mlx = NULL;
	new_data->win = NULL;
	new_data->posX = -99;
	new_data->posY = -99;
	new_data->mapX = -99;
	new_data->mapY = -99;
	new_data->map_x = -99;
	new_data->map_y = -99;
	new_data->dirX = -99;
	new_data->dirY = -99;
	new_data->planeX = -99;
	new_data->planeY = -99;
	new_data->rayDirX = -99;
	new_data->rayDirY = -99;
	new_data->sideDistX = -99;
	new_data->sideDistY = -99;
	new_data->deltaDistX = -99;
	new_data->deltaDistY = -99;
	new_data->stepX = -99;
	new_data->stepY = -99;
	new_data->time = 0;
	new_data->old_time = 0;
	return(new_data);
}