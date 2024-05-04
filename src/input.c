/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:00:02 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 16:03:42 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = data->playerDirX;
	old_planeX = data->planeX;
	data->playerDirX = data->playerDirX * cos(ROT_SPEED) - data->playerDirY * sin(ROT_SPEED);
	data->playerDirY = old_playerDirX * sin(ROT_SPEED) + data->playerDirY * cos(ROT_SPEED);
	data->planeX = data->planeX * cos(ROT_SPEED) - data->planeY * sin(ROT_SPEED);
	data->planeY = old_planeX * sin(ROT_SPEED) + data->planeY * cos(ROT_SPEED);
}

void	rotate_right(t_data *data)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = data->playerDirX;
	old_planeX = data->planeX;
	data->playerDirX = data->playerDirX * cos(-ROT_SPEED) - data->playerDirY * sin(-ROT_SPEED);
	data->playerDirY = old_playerDirX * sin(-ROT_SPEED) + data->playerDirY * cos(-ROT_SPEED);
	data->planeX = data->planeX * cos(-ROT_SPEED) - data->planeY * sin(-ROT_SPEED);
	data->planeY = old_planeX * sin(-ROT_SPEED) + data->planeY * cos(-ROT_SPEED);
}

void	move_forward(t_data *data)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = data->playerDirX;
	old_planeX = data->planeX;
	data->playerDirX = data->playerDirX * cos(ROT_SPEED) - data->playerDirY * sin(ROT_SPEED);
	data->playerDirY = old_playerDirX * sin(ROT_SPEED) + data->playerDirY * cos(ROT_SPEED);
	data->planeX = data->planeX * cos(ROT_SPEED) - data->planeY * sin(ROT_SPEED);
	data->planeY = old_planeX * sin(ROT_SPEED) + data->planeY * cos(ROT_SPEED);
}

void	move_backward(t_data *data)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = data->playerDirX;
	old_planeX = data->planeX;
	data->playerDirX = data->playerDirX * cos(-ROT_SPEED) - data->playerDirY * sin(-ROT_SPEED);
	data->playerDirY = old_playerDirX * sin(-ROT_SPEED) + data->playerDirY * cos(-ROT_SPEED);
	data->planeX = data->planeX * cos(-ROT_SPEED) - data->planeY * sin(-ROT_SPEED);
	data->planeY = old_planeX * sin(-ROT_SPEED) + data->planeY * cos(-ROT_SPEED);
}

void	process_input(t_data *data)
{
	if (data->up_pressed)
		move_forward(data);
	if (data->down_pressed)
		move_backward(data);
	if (data->left_pressed)
		rotate_left(data);
	if (data->up_pressed)
		rotate_right(data);
}