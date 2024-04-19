/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/19 03:22:55 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_walls_texture(int fd, t_data *data)
{
	char	**array;
	int		textures_found;
	char	*line;

	textures_found = 0;
	while(textures_found < 4)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		array = ft_split(line, ' ');
		if (!ft_strcmp(array[0], "NO"))
			data->no_texture = strdup(array[1]);
		else if (!ft_strcmp(array[0], "SO"))
			data->so_texture = strdup(array[1]);
		else if (!ft_strcmp(array[0], "EA"))
			data->ea_texture = strdup(array[1]);
		else if (!ft_strcmp(array[0], "WE"))
			data->we_texture = strdup(array[1]);
		else
		{
			free_2darray(&array);
			continue;
		}
		free_2darray(&array);
		textures_found++;
	}
}

void	parse_scene(t_data *data)
{
	int	fd;

	fd = open(data->filepath, O_RDONLY);
	get_walls_texture(fd, data);
	print_data(data);
	// get_floor_ceiling_texture(fd, data);
	// parse_map(fd, data);
}