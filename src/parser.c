/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 18:16:44 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	process_line(char **array, t_data *data)
{
	data->textures_path = malloc(sizeof(char *) * 4);
	if (!data->textures_path)
		ft_error(data, "failed to malloc images array", 1);
	data->textures_path[0] = NULL;
	data->textures_path[1] = NULL;
	data->textures_path[2] = NULL;
	data->textures_path[3] = NULL;
	if (!ft_strcmp(array[0], "NO") && !data->textures_path[0])
		data->textures_path[0] = strdup(array[1]);
	else if (!ft_strcmp(array[0], "SO") && !data->textures_path[1])
		data->textures_path[1] = strdup(array[1]);
	else if (!ft_strcmp(array[0], "EA") && !data->textures_path[2])
		data->textures_path[2] = strdup(array[1]);
	else if (!ft_strcmp(array[0], "WE") && !data->textures_path[3])
		data->textures_path[3] = strdup(array[1]);
	else if (!ft_strcmp(array[0], "F") && data->floor_color == -1)
		data->floor_color = rgb_to_int(ft_split(array[1], ','));
	else if (!ft_strcmp(array[0], "C") && data->ceiling_color == -1)
		data->ceiling_color = rgb_to_int(ft_split(array[1], ','));
	else
		ft_error(data, "Incorrect/duplicate identifier", 1);

}

void	parse_textures(int fd, t_data *data)
{
	char	**array;
	int		textures_found;
	char	*line;

	array = NULL;
	textures_found = 0;
	while (textures_found < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_trimnl(line);
		array = ft_split(line, ' ');
		if (array && array[0] && array[1])
		{
			if (array[2])
				ft_error(data, "Wrong color/texture format", 1);
			process_line(array, data);
			textures_found++;
		}
		free_2darray(&array);
		free(line);
	}
}

t_list	*parse_map_to_list(int fd, t_data *data)
{
	char	*line;
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
		ft_trimnl(line);
		list_addback(list_new(line), &lst, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lst);
}

void	parse_direction_and_plane(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == P_NORTH)
	{
		data->scene->player_diry = -1;
		data->scene->plane_x = 0.66;
	}
	else if (data->map[data->player_y][data->player_x] == P_SOUTH)
	{
		data->scene->player_diry = 1;
		data->scene->plane_x = 0.66;
	}
	else if (data->map[data->player_y][data->player_x] == P_EAST)
	{
		data->scene->player_dirx = 1;
		data->scene->plane_y = 0.66;
	}
	else if (data->map[data->player_y][data->player_x] == P_WEST)
	{
		data->scene->player_dirx = -1;
		data->scene->plane_y = 0.66;
	}
}

void	parse_scene(t_data *data)
{
	int	fd;

	fd = open(data->filepath, O_RDONLY);
	parse_textures(fd, data);
	data->lst = parse_map_to_list(fd, data);
	data->map = parse_list_to_array(data->lst, data);
	parse_direction_and_plane(data);
}
