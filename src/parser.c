/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 22:33:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_walls_texture(int fd, t_data *data)
{
	char	**array;
	int		textures_found;

	textures_found = 0;
	while(textures_found < 4)
	{
		array = ft_split(get_next_line(fd), " ");
		if (ft_strcmp(array[0], "NO"))
			data->no_texture = strdup(array[1]);
		else if (ft_strcmp(array[0], "SO"))
			data->so_texture = strdup(array[1]);
		else if (ft_strcmp(array[0], "EA"))
			data->ea_texture = strdup(array[1]);
		else if (ft_strcmp(array[0], "WE"))
			data->we_texture = strdup(array[1]);
		free_2darray(array);
	}
}

void	parse_scene(t_data *data)
{
	int	fd;

	fd = open(data->filepath, O_RDONLY);
	get_walls_texture(fd, data);
	// get_floor_ceiling_texture(fd, data);
	// parse_map(fd, data);
}