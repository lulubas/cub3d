/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/05/24 19:11:26 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 * 1. Check if string length is valid ( > .cub'\0')
 * 2. Check that the last for chars are ".cub"
*/
static int	check_file_type(char *str)
{
	if (ft_strlen(str) < 5)
		return (1);
	else if (ft_strncmp(".cub", str + ft_strlen(str) - 4, 4))
		return (1);
	return (0);
}

static void	check_textures_and_colors(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	ft_trimnl(line);
	while ((!is_map_line(line) || *line == '\0') && i < 6)
	{
		if (line && *line != '\0')
			is_texorcolor(data, line, &i);
		free(line);
		line = get_next_line(fd);
		ft_trimnl(line);
	}
	if (i != 6)
		ft_error(data, "Invalid configuraton found in file", 1);
}

void	check_scene(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		ft_error(data, "Invalid number of arguments", 1);
	if (check_file_type(argv[1]))
		ft_error(data, "Map file extension must be '.cub'", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(data, "Map file could not be opened", 1);
	check_textures_and_colors(data, fd);
	data->filepath = ft_strdup(argv[1]);
	close(fd);
}
