/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:00:02 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 20:42:45 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double old_playerDirX;
	double old_planeX;

	printf("LEFT\n");
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

	printf("RIGHT\n");
	old_playerDirX = data->playerDirX;
	old_planeX = data->planeX;
	data->playerDirX = data->playerDirX * cos(-ROT_SPEED) - data->playerDirY * sin(-ROT_SPEED);
	data->playerDirY = old_playerDirX * sin(-ROT_SPEED) + data->playerDirY * cos(-ROT_SPEED);
	data->planeX = data->planeX * cos(-ROT_SPEED) - data->planeY * sin(-ROT_SPEED);
	data->planeY = old_planeX * sin(-ROT_SPEED) + data->planeY * cos(-ROT_SPEED);
}

void	move_forward(t_data *data)
{
	double new_playerPosX;
	double new_playerPosY;

	printf("UP\n");
	new_playerPosX = data->playerPosX + (data->playerDirX * MOVE_SPEED);
	new_playerPosY = data->playerPosY + (data->playerDirY * MOVE_SPEED);
	printf("playerPosY=%f new_playerPosY=%f playerDirY=%f\n", data->playerPosY, new_playerPosY, data->playerDirY);
	if(data->map[(int)new_playerPosY][(int)new_playerPosX] != WALL)
	{
		printf("NO WALL\n");
		data->playerPosX = new_playerPosX;
		data->playerPosY = new_playerPosY;
	}
}

void	move_backward(t_data *data)
{
	double new_playerPosX;
	double new_playerPosY;

	printf("DOWN\n");
	new_playerPosX = data->playerPosX - data->playerDirX * MOVE_SPEED;
	new_playerPosY = data->playerPosY - data->playerDirY * MOVE_SPEED;
	if(data->map[(int)new_playerPosY][(int)new_playerPosX] != WALL)
	{
		data->playerPosX = new_playerPosX;
		data->playerPosY = new_playerPosY;
	}
}

void	process_input(t_data *data)
{
	if (data->up_pressed == true)
		move_forward(data);
	if (data->down_pressed == true)
		move_backward(data);
	if (data->left_pressed == true)
		rotate_left(data);
	if (data->right_pressed == true)
		rotate_right(data);
}