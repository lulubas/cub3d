/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:00:02 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:21:23 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_scene *scene)
{
	double	old_playerdirx;
	double	old_plane_x;

	old_playerdirx = scene->player_dirx;
	old_plane_x = scene->plane_x;
	scene->player_dirx = scene->player_dirx * cos(-ROT_SPEED) -\
						scene->player_diry * sin(-ROT_SPEED);
	scene->player_diry = old_playerdirx * sin(-ROT_SPEED) + \
						scene->player_diry * cos(-ROT_SPEED);
	scene->plane_x = scene->plane_x * cos(-ROT_SPEED) - \
						scene->plane_y * sin(-ROT_SPEED);
	scene->plane_y = old_plane_x * sin(-ROT_SPEED) + \
						scene->plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_scene *scene)
{
	double	old_playerdirx;
	double	old_plane_x;

	old_playerdirx = scene->player_dirx;
	old_plane_x = scene->plane_x;
	scene->player_dirx = scene->player_dirx * cos(ROT_SPEED) - \
						scene->player_diry * sin(ROT_SPEED);
	scene->player_diry = old_playerdirx * sin(ROT_SPEED) + \
						scene->player_diry * cos(ROT_SPEED);
	scene->plane_x = scene->plane_x * cos(ROT_SPEED) - \
						scene->plane_y * sin(ROT_SPEED);
	scene->plane_y = old_plane_x * sin(ROT_SPEED) + \
						scene->plane_y * cos(ROT_SPEED);
}

void	process_input(t_data *data)
{
	if (data->up_pressed == true)
		move_forward(data->scene, data->map);
	if (data->down_pressed == true)
		move_backward(data->scene, data->map);
	if (data->left_pressed == true)
		move_left(data->scene, data->map);
	if (data->right_pressed == true)
		move_right(data->scene, data->map);
	if (data->left_rotate_pressed == true)
		rotate_left(data->scene);
	if (data->right_rotate_pressed == true)
		rotate_right(data->scene);
}
