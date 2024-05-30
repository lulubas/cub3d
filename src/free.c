/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:59:26 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/30 16:53:35 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_tile ***map, t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map_size_y)
	{
		free((*map)[y]);
		y++;
	}
	free(*map);
	*map = NULL;
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->filepath)
			free(data->filepath);
		if (data->textures_path)
			free_tex_paths(&data->textures_path);
		if (data->textures_ptr)
			free_tex_ptr(&data->textures_ptr, data);
		if (data->lst)
			free_list(&data->lst);
		if (data->map)
			free_map(&data->map, data);
		if (data->scene)
			free(data->scene);
		data->scene = NULL;
		free(data->mlx);
		free(data);
		data = NULL;
	}
}

void	ft_error(t_data *data, char *str, int status)
{
	if (status)
		write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free_all(data);
	exit(status);
}
