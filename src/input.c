/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:00:02 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 13:17:24 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_scene *scene)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = scene->playerDirX;
	old_planeX = scene->planeX;
	scene->playerDirX = scene->playerDirX * cos(-ROT_SPEED) - scene->playerDirY * sin(-ROT_SPEED);
	scene->playerDirY = old_playerDirX * sin(-ROT_SPEED) + scene->playerDirY * cos(-ROT_SPEED);
	scene->planeX = scene->planeX * cos(-ROT_SPEED) - scene->planeY * sin(-ROT_SPEED);
	scene->planeY = old_planeX * sin(-ROT_SPEED) + scene->planeY * cos(-ROT_SPEED);
}

void	rotate_right(t_scene *scene)
{
	double old_playerDirX;
	double old_planeX;

	old_playerDirX = scene->playerDirX;
	old_planeX = scene->planeX;
	scene->playerDirX = scene->playerDirX * cos(ROT_SPEED) - scene->playerDirY * sin(ROT_SPEED);
	scene->playerDirY = old_playerDirX * sin(ROT_SPEED) + scene->playerDirY * cos(ROT_SPEED);
	scene->planeX = scene->planeX * cos(ROT_SPEED) - scene->planeY * sin(ROT_SPEED);
	scene->planeY = old_planeX * sin(ROT_SPEED) + scene->planeY * cos(ROT_SPEED);
}

void	move_forward(t_scene *scene, t_tile **map)
{
	double	new_playerPosX;
	double	new_playerPosY;
	double	player_bound;

	player_bound = 0.1;
	new_playerPosX = scene->playerPosX + (scene->playerDirX * MOVE_SPEED);
	new_playerPosY = scene->playerPosY + (scene->playerDirY * MOVE_SPEED);
	if(map[(int)(new_playerPosY + player_bound)][(int)(new_playerPosX + player_bound)] != WALL)
	{
		scene->playerPosX = new_playerPosX;
		scene->playerPosY = new_playerPosY;
	}
}

void	move_backward(t_scene *scene, t_tile **map)
{
	double new_playerPosX;
	double new_playerPosY;
	double	player_bound;

	player_bound = 0.1;
	new_playerPosX = scene->playerPosX - (scene->playerDirX * MOVE_SPEED);
	new_playerPosY = scene->playerPosY - (scene->playerDirY * MOVE_SPEED);
	if(map[(int)(new_playerPosY + player_bound)][(int)(new_playerPosX + player_bound)] != WALL)
	{
		scene->playerPosX = new_playerPosX;
		scene->playerPosY = new_playerPosY;
	}
}

void	process_input(t_data *data)
{
	if (data->up_pressed == true)
		move_forward(data->scene, data->map);
	if (data->down_pressed == true)
		move_backward(data->scene, data->map);
	if (data->left_pressed == true)
		rotate_left(data->scene);
	if (data->right_pressed == true)
		rotate_right(data->scene);
}