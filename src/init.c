/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/29 14:51:09 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	*init_scene(void)
{
	t_scene	*new_scene;

	new_scene = malloc(sizeof(t_scene));
	new_scene->player_posx = -99;
	new_scene->player_posy = -99;
	new_scene->player_dirx = 0;
	new_scene->player_diry = 0;
	new_scene->ray_dirx = -99;
	new_scene->ray_diry = -99;
	new_scene->plane_x = 0;
	new_scene->plane_y = 0;
	new_scene->side_distx = -99;
	new_scene->side_disty = -99;
	new_scene->delta_distx = -99;
	new_scene->delta_disty = -99;
	new_scene->map_x = -99;
	new_scene->map_y = -99;
	new_scene->step_x = -99;
	new_scene->step_y = -99;
	new_scene->perp_walldist = -99;
	new_scene->line_height = -99;
	new_scene->draw_start = -99;
	new_scene->draw_end = -99;
	return (new_scene);
}

void	init_tex_arrays(t_data *data)
{
	int	i;

	i = 0;
	data->textures_path = malloc(sizeof(char *) * 4);
	data->textures_ptr = malloc(sizeof(void *) * 4);
	if (!data->textures_path || !data->textures_ptr)
		ft_error(data, "Failed to malloc textures array", 1);
	while (i < 4)
	{
		data->textures_path[i] = NULL;
		data->textures_ptr[i] = NULL;
		i++;
	}
}

t_data	*init_data_struct(void)
{
	t_data	*new_data;

	new_data = malloc(sizeof(t_data));
	new_data->filepath = NULL;
	new_data->floor_color = -1;
	new_data->ceiling_color = -1;
	new_data->map_size_x = 0;
	new_data->map_size_y = 0;
	new_data->lst = NULL;
	new_data->map = NULL;
	new_data->scene = init_scene();
	new_data->mlx = NULL;
	new_data->win = NULL;
	new_data->player_x = -99;
	new_data->player_y = -99;
	new_data->up_pressed = false;
	new_data->down_pressed = false;
	new_data->left_pressed = false;
	new_data->right_pressed = false;
	new_data->left_rotate_pressed = false;
	new_data->right_rotate_pressed = false;
	init_tex_arrays(new_data);
	return (new_data);
}
