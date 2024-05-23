/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:19 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:31:14 by lbastien         ###   ########.fr       */
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

t_data	*init_data_struct(void)
{
	t_data	*new_data;

	new_data = malloc(sizeof(t_data));
	new_data->filepath = NULL;
	new_data->textures_path = NULL;
	new_data->textures_ptr = NULL;
	new_data->floor_color = -1;
	new_data->ceiling_color = -1;
	new_data->map_size_x = 0;
	new_data->map_size_y = 0;
	new_data->lst = NULL;
	new_data->map = NULL;
	new_data->scene = init_scene();
	new_data->buffer = NULL;
	new_data->mlx = NULL;
	new_data->win = NULL;
	new_data->map_size_x = -99;
	new_data->map_size_y = -99;
	new_data->up_pressed = false;
	new_data->down_pressed = false;
	new_data->left_rotate_pressed = false;
	new_data->right_rotate_pressed = false;
	return (new_data);
}

int	get_max_x(t_list *lst)
{
	t_list	*tmp;
	size_t	max_length;

	max_length = 0;
	tmp = lst;
	while (tmp)
	{
		if (ft_strlen(tmp->str) > max_length)
			max_length = ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (max_length + 2);
}

int	get_y(t_list *lst)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = lst;
	while (tmp)
	{
		index++;
		tmp = tmp->next;
	}
	return (index + 2);
}

t_tile	**init_map(t_list *lst, t_data *data)
{
	t_tile	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map_size_x = get_max_x(lst);
	data->map_size_y = get_y(lst);
	new_map = (t_tile **)malloc(sizeof(t_tile *) * data->map_size_y);
	if (!new_map)
		ft_error(data, "Failed to allocate map", 1);
	while (i < data->map_size_y)
	{
		new_map[i] = (t_tile *)malloc(sizeof(t_tile) * data->map_size_x);
		if (!new_map[i])
			ft_error(data, "Failed to allocate map tiles", 1);
		while (j < data->map_size_x)
			new_map[i][j++] = SPACE;
		j = 0;
		i++;
	}
	return (new_map);
}
