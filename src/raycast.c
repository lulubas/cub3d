/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:01 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:23:59 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Side distances from Player to next grid lines
void	parse_sidedist(t_scene *scene)
{
	if (scene->ray_dirx < 0)
	{
		scene->step_x = -1;
		scene->side_distx = (scene->player_posx - scene->map_x) \
		* scene->delta_distx;
	}
	else
	{
		scene->step_x = 1;
		scene->side_distx = (scene->map_x + 1 - scene->player_posx) \
		* scene->delta_distx;
	}
	if (scene->ray_diry < 0)
	{
		scene->step_y = -1;
		scene->side_disty = (scene->player_posy - scene->map_y) \
		* scene->delta_disty;
	}
	else
	{
		scene->step_y = 1;
		scene->side_disty = (scene->map_y + 1.0 - scene->player_posy) \
		* scene->delta_disty;
	}
}

//Get Rays vectors from the Player through the plane
//and initial position of rays
void	init_rays(int x, int width, t_scene *scene)
{
	double	cam_x;

	cam_x = 2 * x / (double)width - 1;
	scene->ray_dirx = scene->player_dirx + scene->plane_x * cam_x;
	scene->ray_diry = scene->player_diry + scene->plane_y * cam_x;
	scene->map_x = (int)scene->player_posx;
	scene->map_y = (int)scene->player_posy;
	if (scene->ray_dirx == 0)
		scene->delta_distx = 1e42;
	else
		scene->delta_distx = fabs(1 / scene->ray_dirx);
	if (scene->ray_diry == 0)
		scene->delta_disty = 1e42;
	else
		scene->delta_disty = fabs(1 / scene->ray_diry);
	parse_sidedist(scene);
}

//DDA aLgorythm to find which wall is hit first
void	perform_dda(t_scene *scene, t_tile **map)
{
	while (1)
	{
		if (scene->side_distx < scene->side_disty)
		{
			scene->side_distx += scene->delta_distx;
			scene->map_x += scene->step_x;
			if (scene->step_x > 0)
				scene->side = WEST;
			else
				scene->side = EAST;
		}
		else
		{
			scene->side_disty += scene->delta_disty;
			scene->map_y += scene->step_y;
			if (scene->step_y > 0)
				scene->side = NORTH;
			else
				scene->side = SOUTH;
		}
		if (map[scene->map_y][scene->map_x] == WALL)
			break ;
	}
}

//Calculate perpendicalr distance of the wall to the plane
//and the line_height zith the the start and end of the wall slice
void	split_slice(t_scene *scene)
{
	if (scene->side == EAST || scene->side == WEST)
		scene->perp_walldist = scene->side_distx - scene->delta_distx;
	else
		scene->perp_walldist = scene->side_disty - scene->delta_disty;
	scene->line_height = (int)((double)SCREEN_HEIGHT / scene->perp_walldist);
	scene->draw_start = -scene->line_height / 2 + SCREEN_HEIGHT / 2;
	if (scene->draw_start < 0)
		scene->draw_start = 0;
	scene->draw_end = scene->line_height / 2 + SCREEN_HEIGHT / 2;
	if (scene->draw_end >= SCREEN_HEIGHT)
		scene->draw_end = SCREEN_HEIGHT - 1;
}
