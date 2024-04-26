/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/26 08:54:54 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	process_line(char **array, t_data *data)
{
	if (!ft_strcmp(array[0], "NO"))
		data->no_texture = strdup(array[1]);
	else if (!ft_strcmp(array[0], "SO"))
		data->so_texture = strdup(array[1]);
	else if (!ft_strcmp(array[0], "EA"))
		data->ea_texture = strdup(array[1]);
	else if (!ft_strcmp(array[0], "WE"))
		data->we_texture = strdup(array[1]);
	else if (!ft_strcmp(array[0], "F"))
		data->F_color = ft_split(array[1], ',');
	else if (!ft_strcmp(array[0], "C"))
		data->C_color = ft_split(array[1], ',');
}

void parse_textures(int fd, t_data *data)
{
	char	**array;
	int		textures_found;
	char	*line;

	textures_found = 0;
	while(textures_found < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		ft_trimnl(line);
		array = ft_split(line, ' ');
		if (array && array[0] && array[1])
		{
			process_line(array, data);
			textures_found++;
		}
		free_2darray(&array);
		free(line);
	}
}

t_list *parse_map_to_list(int fd, t_data *data)
{
	char 	*line;
	t_list	*lst;

	lst = NULL;
	line = get_next_line(fd);
	while (!ft_strchr(line, '1'))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && ft_strchr(line, '1'))
	{
		list_addback(list_new(line), &lst, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lst);
}

void	parse_scene(t_data *data)
{
	int		fd;

	fd = open(data->filepath, O_RDONLY);
	parse_textures(fd, data);
	data->lst = parse_map_to_list(fd, data);
	data->map = parse_list_to_array(data->lst, data);
}