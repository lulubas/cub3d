/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 15:27:08 by lbastien         ###   ########.fr       */
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
	new_data->map_x = -1;
	new_data->map_y = -1;
	new_data->dirX = -1;
	new_data->dirY = -1;
	new_data->planeX = -1;
	new_data->planeY = -1;
	new_data->time = 0;
	new_data->old_time = 0;
	return(new_data);
}