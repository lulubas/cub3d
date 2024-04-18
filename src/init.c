/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 21:57:37 by lbastien         ###   ########.fr       */
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
	new_data->mlx = NULL;
	new_data->win = NULL;
	return(new_data);
}