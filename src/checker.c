/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/05/24 15:06:35 by lbastien         ###   ########.fr       */
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

/*
 * 1. Keep getting_next_line from fd until we found 6 
	lines that are textures/colors
 * 2. If line is valid and not a mapline, check if its
	a correct texture/color and increment line num counter
*/
static void	check_textures_and_colors(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line && i < 6)
	{
		if (*line != '\n' && line && !is_map_line(line))
			is_texorcolor(data, line, &i);
		if (line && *line != '\n' && is_map_line(line) && i < 6)
			ft_error(data, "Could not find 4 textures and 2 colors", 1);
		free(line);
		if (i < 6)
			line = get_next_line(fd);
	}
	if (i != 6)
		ft_error(data, "Could not find 4 textures and 2 colors", 1);
}
/*
 * 1. After the textures and colors have been checked and
 * are correct, 
*/
// void	check_invalid_config(t_data *data, int fd)
// {

// }

/*
 * 1. Check number of input arguments 
 * 2. Check if input argument file type is valid (.cub)
 * 3. Open file checking for error
 * 4. Find/check for textures and colors from scene file
*/
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
	//check_invalid_config(data, fd);
	data->filepath = ft_strdup(argv[1]);
	close(fd);
}