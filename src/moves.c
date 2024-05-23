/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:42:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:23:11 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_scene *scene, t_tile **map)
{
	double	new_playerposx;
	double	new_playerpos_y;

	new_playerposx = scene->player_posx + (scene->player_dirx * MOVE_SPEED);
	new_playerpos_y = scene->player_posy + (scene->player_diry * MOVE_SPEED);
	if (map[(int)(new_playerpos_y)][(int)(new_playerposx)] != WALL)
	{
		scene->player_posx = new_playerposx;
		scene->player_posy = new_playerpos_y;
	}
}

void	move_backward(t_scene *scene, t_tile **map)
{
	double	new_playerposx;
	double	new_playerpos_y;

	new_playerposx = scene->player_posx - (scene->player_dirx * MOVE_SPEED);
	new_playerpos_y = scene->player_posy - (scene->player_diry * MOVE_SPEED);
	if (map[(int)(new_playerpos_y)][(int)(new_playerposx)] != WALL)
	{
		scene->player_posx = new_playerposx;
		scene->player_posy = new_playerpos_y;
	}
}

void	move_left(t_scene *scene, t_tile **map)
{
	double	new_playerposx;
	double	new_playerpos_y;

	new_playerposx = scene->player_posx - (scene->plane_x * MOVE_SPEED);
	new_playerpos_y = scene->player_posy - (scene->plane_y * MOVE_SPEED);
	if (map[(int)(new_playerpos_y)][(int)(new_playerposx)] != WALL)
	{
		scene->player_posx = new_playerposx;
		scene->player_posy = new_playerpos_y;
	}
}

void	move_right(t_scene *scene, t_tile **map)
{
	double	new_playerposx;
	double	new_playerpos_y;

	new_playerposx = scene->player_posx + (scene->plane_x * MOVE_SPEED);
	new_playerpos_y = scene->player_posy + (scene->plane_y * MOVE_SPEED);
	if (map[(int)(new_playerpos_y)][(int)(new_playerposx)] != WALL)
	{
		scene->player_posx = new_playerposx;
		scene->player_posy = new_playerpos_y;
	}
}
